#include <iostream>
#include <fstream>
#include <vector>

#include "consts.h"
#include "split.h"
#include "solution.h"

std::ifstream fileSolution;
int main() {
    Solution sol;
    std::cout << "Worked solution: " << SOLUTION << std::endl;
    fileSolution.open(SOLUTION,std::fstream::in | std::fstream::out | std::fstream::app);
    if(fileSolution.is_open()) {
        std::cout << "Opened" << std::endl;
        std::string str;
        while(getline(fileSolution, str, '\n'))
        {
            //std::cout<<str<<std::endl;

            std::size_t foundVSVersion = str.find("VisualStudioVersion");
            std::size_t foundMinVersion = str.find("MinimumVisualStudioVersion");

            if(foundVSVersion != std::string::npos && foundMinVersion == std::string::npos)
            {
                std::vector<std::string> vec = split(str, '=');
                if(vec.size() >= 2)sol.setVisualStudioVersion(vec[1]);
            }
            if(foundMinVersion != std::string::npos)
            {
                std::vector<std::string> vec = split(str, '=');
                if(vec.size() >= 2)sol.setMinimumVisualStudioVersion(vec[1]);
            }

        }
    }
    else std::cout << "File solution not found"<<std::endl;
    fileSolution.close();
    if(!fileSolution.is_open()) std::cout << "File solution is closed" << std::endl;
    std::cout<<sol<<std::endl;
    return 0;
}