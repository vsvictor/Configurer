//
// Created by User on 2/9/2018.
//

#ifndef CONFIGURER_PROJECT_H
#define CONFIGURER_PROJECT_H

#include <string>

class Project {
private:
    std::string id;
    std::string type;
    std::string name;
    std::string fileName;
public:
    Project();
    ~Project();

    void setID(std::string aID);
    const std::string& getID()const;
    void setType(std::string aType);
    const std::string& getType()const;
    void setName(std::string aName);
    const std::string& getName()const;
    void setFileName(std::string aFileName);
    const std::string& getFileName()const;
    friend std::ostream& operator<<(std::ostream& os, const Project& p);
};


#endif //CONFIGURER_PROJECT_H
