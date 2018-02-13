cmake_minimum_required(VERSION 3.9)
project(Configurer)

#set (Boost_NO_SYSTEM_PATHS ON)
#set (Boost_USE_MULTITHREADED ON)
#set (Boost_USE_STATIC_LIBS ON)
#set (Boost_USE_STATIC_RUNTIME ON)
#set (BOOST_ALL_DYN_LINK OFF)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lboost_system")

set (BOOST_ROOT "C:/BuildTools/boost")
set(BOOST_LIB_VERSION "1_60")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib/boost-${BOOST_LIB_VERSION}/win/x86_64")
set (BOOST_INCLUDEDIR "${BOOST_ROOT}/include/boost-${BOOST_LIB_VERSION}")

#set(Boost_SYSTEM_LIBRARY "${BOOST_LIBRARYDIR}/libboost_system-vc120-mt-1_60.lib")
#set(Boost_FILESYSTEM_LIBRARY "${BOOST_LIBRARYDIR}/libboost_filesystem-vc120-mt-1_60.lib")

set(Boost_SYSTEM_LIBRARY "C:/BuildTools/boost/lib/boost-1_60/win/x86/libboost_thread-vc120-mt-1_60.lib")
set(Boost_SYSTEM_LIBRARY "C:/BuildTools/boost/lib/boost-1_60/win/x86/libboost_system-vc120-mt-1_60.lib")
set(Boost_FILESYSTEM_LIBRARY "C:/BuildTools/boost/lib/boost-1_60/win/x86/libboost_filesystem-vc120-mt-1_60.lib")

set(Boost_LIBRARIES ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY})

message(${Boost_SYSTEM_LIBRARY})
message(${Boost_FILESYSTEM_LIBRARY})

include_directories(${BOOST_INCLUDEDIR})
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${BOOST_LIBRARYDIR}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lboost_system")

#target_link_libraries(Configurer ${Boost_SYSTEM_LIBRARY})
#target_link_libraries(Configurer ${Boost_FILESYSTEM_LIBRARY})
target_link_libraries(Configurer ${Boost_LIBRARIES})

add_executable(Configurer main.cpp consts.h split.h solution.cpp solution.h project.cpp project.h pugiconfig.hpp pugixml.hpp pugixml.cpp)

