cmake_minimum_required(VERSION 3.10)
project(Configurer)

add_executable(${PROJECT_NAME} main.cpp consts.h split.h solution.cpp solution.h project.cpp project.h pugiconfig.hpp pugixml.hpp pugixml.cpp)
target_link_libraries(${PROJECT_NAME} libstdc++fs.a)