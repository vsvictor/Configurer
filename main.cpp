#include <iostream>
#include <fstream>
#include <vector>

#include "consts.h"
#include "split.h"
#include "solution.h"

#include "pugixml.hpp"

Solution parseSolution(std::string nameSolution) {
    Solution sol;
    std::ifstream fileSolution;
    std::cout << "Worked solution: " << nameSolution << std::endl;
    fileSolution.open(nameSolution,std::fstream::in | std::fstream::out | std::fstream::app);
    if(fileSolution.is_open()) {
        std::cout << "Opened" << std::endl;
        std::string str;
        while(getline(fileSolution, str, '\n'))
        {
            //std::cout<<str<<std::endl;

            std::size_t foundVSVersion = str.find("VisualStudioVersion");
            std::size_t foundMinVersion = str.find("MinimumVisualStudioVersion");
            std::size_t foundProject = str.find("Project");
            std::size_t foundEndProject = str.find("EndProject");
            std::size_t foundGlobal = str.find("Global");
            std::size_t foundGlobalSection = str.find("GlobalSection");

            if(foundVSVersion != std::string::npos && foundMinVersion == std::string::npos)
            {
                std::vector<std::string> vec = split(str, '=');
                if(vec.size() >= 2)sol.setVisualStudioVersion(vec[1]);
            }
            else if(foundMinVersion != std::string::npos)
            {
                std::vector<std::string> vec = split(str, '=');
                if(vec.size() >= 2)sol.setMinimumVisualStudioVersion(vec[1]);
            }
            else if(foundProject != std::string::npos && foundEndProject == std::string::npos && foundGlobalSection == std::string::npos)
            {
                Project pj;
                std::vector<std::string> st = split(str, '=');
                //if(st.size()>1) {
                    std::vector<std::string> other = split(st[1], ',');
                    //if(other.size()>1) {
                        pj.setType(st[0].substr(8, 40));
                        pj.setName(other[0]);
                        pj.setFileName(other[1].substr(2,other[1].size()-3));
                        pj.setID(other[2]);
                        sol.addProject(pj);
                    //}
                //}
            }
            else
            {
                sol.addOther(str);
            }
        }
    }
    else std::cout << "File solution not found"<<std::endl;
    fileSolution.close();
    if(!fileSolution.is_open()) std::cout << "File solution is closed" << std::endl;
    return sol;
}

int main()
{
    Solution solution = parseSolution(SOLUTION);
    std::cout<<solution<<std::endl;
    for(int i = 0;i<solution.getProjects().size();i++)
    {
        Project p = solution.getProject(i);
        std::string fileName = PREFIX+p.getFileName();
        pugi::xml_document doc;
        pugi::xml_parse_result res = doc.load_file(fileName.c_str());
        std::cout<<"Parsed"<<std::endl;
    }
}
