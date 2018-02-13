#include <iostream>
#include <fstream>
#include <vector>
#include <experimental/filesystem>

#include "consts.h"
#include "split.h"
#include "solution.h"

#include "pugixml.hpp"

#include <boost/filesystem.hpp>


Solution parseSolution(std::string nameSolution) {
    Solution sol;
    std::ifstream fileSolution;
    std::cout << "Worked solution: " << nameSolution << std::endl;
    fileSolution.open(nameSolution, std::fstream::in | std::fstream::out | std::fstream::app);
    if (fileSolution.is_open()) {
        std::cout << "Opened" << std::endl;
        std::string str;
        while (getline(fileSolution, str, '\n')) {
            //std::cout<<str<<std::endl;

            std::size_t foundVSVersion = str.find("VisualStudioVersion");
            std::size_t foundMinVersion = str.find("MinimumVisualStudioVersion");
            std::size_t foundProject = str.find("Project");
            std::size_t foundEndProject = str.find("EndProject");
            std::size_t foundGlobal = str.find("Global");
            std::size_t foundGlobalSection = str.find("GlobalSection");

            if (foundVSVersion != std::string::npos && foundMinVersion == std::string::npos) {
                std::vector<std::string> vec = split(str, '=');
                if (vec.size() >= 2)sol.setVisualStudioVersion(vec[1]);
            } else if (foundMinVersion != std::string::npos) {
                std::vector<std::string> vec = split(str, '=');
                if (vec.size() >= 2)sol.setMinimumVisualStudioVersion(vec[1]);
            } else if (foundProject != std::string::npos && foundEndProject == std::string::npos &&
                       foundGlobalSection == std::string::npos) {
                Project pj;
                std::vector<std::string> st = split(str, '=');
                std::vector<std::string> other = split(st[1], ',');
                pj.setType(st[0].substr(8, 40));
                pj.setName(other[0].substr(2, other[0].size() - 3));
                pj.setFileName(other[1].substr(2, other[1].size() - 3));
                pj.setID(other[2]);
                sol.addProject(pj);
            } else {
                sol.addOther(str);
            }
        }
    } else std::cout << "File solution not found" << std::endl;
    fileSolution.close();
    if (!fileSolution.is_open()) std::cout << "File solution is closed" << std::endl;
    return sol;
}

int main() {
    Solution solution = parseSolution(PREFIX + "\\" + SOLUTION);
    std::cout << solution << std::endl;

    for (int i = 0; i < solution.getProjects().size(); i++) {
        std::string pName = std::string(solution.getProject(i).getName());
        if (pName == std::string("base")) {
            Project p = solution.getProject(i);
            std::cout << p.getFileName() << std::endl;
            pugi::xml_document doc;
            pugi::xml_document new_root;
            pugi::xml_parse_result res = doc.load_file(p.getFileName().c_str());
            pugi::xml_node root = doc.document_element();
            std::cout << res.description() << std::endl;
            std::cout << "Root: " << root.name() << std::endl;
            pugi::xml_node::iterator itRoot = root.begin();
            new_root.root().append_child("Project");
            pugi::xml_node result = new_root.child("Project");
            pugi::xml_attribute_iterator itAtt = root.attributes_begin();
            do {
                //std::cout<<itAtt->name()<<"="<<itAtt->value()<<std::endl;
                result.append_attribute(itAtt->name()).set_value(itAtt->value());
                itAtt++;
            } while (itAtt != root.attributes_end());

            do {
                if (std::string(itRoot->name()) == std::string("ItemGroup")) {
                    pugi::xml_node nIG = result.append_child("ItemGroup");
                    pugi::xml_node::iterator itIG = itRoot->begin();
                    do {
                        if (std::string(itIG->name()) == std::string("ProjectConfiguration")) {
                            pugi::xml_attribute atInclude = itIG->attribute("Include");
                            std::string sAtt = std::string(atInclude.value());
                            if (sAtt.find(CONFIG_NAME) != std::string::npos) {
                                nIG.append_copy(*itIG);
                                std::cout << itIG->name() << sAtt << std::endl;
                            }
                        } else if (std::string(itIG->name()) == std::string("ClInclude")) {
                            nIG.append_copy(*itIG);
                        }
                        itIG++;
                    } while (itIG != itRoot->end());
                    std::cout << itRoot->name() << std::endl;
                }
                itRoot++;
            } while (itRoot != root.end());
            boost::filesystem::path full_path(boost::filesystem::current_path());
            //new_root.save_file((p.getFileName() + ".new").c_str(), "    ", pugi::format_default, pugi::encoding_utf8);
        }
    }
}
