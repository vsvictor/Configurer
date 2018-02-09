cmake_minimum_required(VERSION 3.9)
project(Configurer)
SET(CMAKE_C_COMPILER C:/MinGW/bin/gcc)
SET(CMAKE_CXX_COMPILER C:/MinGW/bin/g++)
set(CMAKE_CXX_STANDARD 11)

add_executable(Configurer main.cpp consts.h split.h solution.cpp solution.h project.cpp project.h)