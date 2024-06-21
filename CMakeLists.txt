cmake_minimum_required(VERSION 3.24)

project(c++_primer)

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(. ./1 ./2)

#foreach(d 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19)

foreach(d 1 2 3 4 5 6)
    add_subdirectory(${d})
endforeach()
