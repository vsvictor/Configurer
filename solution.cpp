//
// Created by User on 2/9/2018.
//

#include <iostream>
#include "solution.h"

Solution::Solution():VisualStudioVersion("0"),MinimumVisualStudioVersion("0")
{
}
Solution::~Solution()
{
}

void Solution::setVisualStudioVersion(std::string version)
{
    VisualStudioVersion = std::string(version);
}
std::string Solution::getVisualStudioVersion()
{
    return VisualStudioVersion;
}

void Solution::setMinimumVisualStudioVersion(std::string version)
{
    MinimumVisualStudioVersion = std::string(version);
}
std::string Solution::getMinimumVisualStudioVersion()
{
    return MinimumVisualStudioVersion;
}
void Solution::addProject(Project project) {
    projects.push_back(project);
}

void Solution::addOther(std::string str)
{
    other.push_back(str);
}

const Project& Solution::getProject(int i)
{
    return projects[i];
}

std::ostream& operator<<(std::ostream& os, Solution& s)
{
    os<<s.getVisualStudioVersion()<<" "<<s.MinimumVisualStudioVersion<<std::endl;
    for(int i=0; i<s.projects.size();i++)
    {
        os<< s.getProject(i) << std::endl;
    }
    for(int i = 0; i<s.other.size();i++)
    {
        os<<s.other[i]<<std::endl;
    }
    return os;
}

std::vector<Project> Solution::getProjects()
{
    return projects;
}