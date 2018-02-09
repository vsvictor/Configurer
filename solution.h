//
// Created by User on 2/9/2018.
//

#ifndef CONFIGURER_SOLUTION_H
#define CONFIGURER_SOLUTION_H


#include <vector>
#include <string>
#include "project.h"


class Solution {
private:
    std::string VisualStudioVersion;
    std::string MinimumVisualStudioVersion;
    std::vector<Project> projects;
public:
    Solution();
    ~Solution();

    void setVisualStudioVersion(std::string version);
    std::string getVisualStudioVersion();
    void setMinimumVisualStudioVersion(std::string version);
    std::string getMinimumVisualStudioVersion();
    void addProject(Project project);
    const Project& getProject(int i);
    friend std::ostream& operator<<(std::ostream& os, Solution& s);
};



#endif //CONFIGURER_SOLUTION_H
