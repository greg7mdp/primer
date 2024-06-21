file(GLOB cpp "*.cpp")

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" dirname ${dirname})

set(my_list fact mainmath) # depend on "LocalMath.h"

foreach(f IN LISTS cpp)
    get_filename_component(target ${f} NAME_WE)
    if ("${target}" IN_LIST my_list)
       add_executable("${target}" "${f}" "LocalMath.h")
    else()
       add_executable("${target}" "${f}")
    endif()
    set_target_properties("${target}" PROPERTIES OUTPUT_NAME "${target}" FOLDER "${dirname}")
endforeach()

