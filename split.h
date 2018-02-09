//
// Created by User on 2/9/2018.
//

#ifndef CONFIGURER_SPLIT_H
#define CONFIGURER_SPLIT_H

#include <iterator>
#include <vector>
#include <sstream>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

#endif //CONFIGURER_SPLIT_H
