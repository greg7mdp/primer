file(GLOB cpp "*.cpp")

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" dirname ${dirname})

set(my_list querymain) #
set(exclude TextQuery) #

include_directories(../6)

foreach(f IN LISTS cpp)
    get_filename_component(target ${f} NAME_WE)
    if ("${target}" IN_LIST exclude)
    else()
       if ("${target}" IN_LIST my_list)
          add_executable("${target}" "${f}" "TextQuery.cpp")
       else()
          add_executable("${target}" "${f}")
       endif()
       set_target_properties("${target}" PROPERTIES OUTPUT_NAME "${target}" FOLDER "${dirname}")
    endif()
endforeach()

