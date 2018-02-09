//
// Created by User on 2/9/2018.
//

#include "project.h"

Project::Project() : id(""),type(""), name(""),fileName("")
{
}

Project::~Project()
{
}

void Project::setID(std::string aID){
    id = aID;
}
const std::string& Project::getID()const
{
    return id;
}
void Project::setType(std::string aType)
{
    type = aType;
}
const std::string& Project::getType()const
{
    return type;
}
void Project::setName(std::string aName)
{
    name = aName;
}
const std::string& Project::getName()const
{
    return name;
}
void Project::setFileName(std::string aFileName)
{
    fileName = aFileName;
}
const std::string& Project::getFileName()const
{
    return fileName;
}

std::ostream& operator<<(std::ostream& os, const Project& p)
{
    os<<p.getID()<<" "<<p.getType()<<" "<<p.getName()<<" "<<p.getFileName();
    return os;
}
