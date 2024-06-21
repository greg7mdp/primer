file(GLOB cpp "*.cpp")

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" dirname ${dirname})

set(my_list add_item add_item2 avg_price item_io) # depend on "Sales_item.h"

foreach(f IN LISTS cpp)
    get_filename_component(target ${f} NAME_WE)
    if ("${target}" IN_LIST my_list)
       add_executable("${target}" "${f}" "Sales_item.h")
    else()
       add_executable("${target}" "${f}")
    endif()
    set_target_properties("${target}" PROPERTIES OUTPUT_NAME "${target}" FOLDER "${dirname}")
endforeach()

