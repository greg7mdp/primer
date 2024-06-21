file(GLOB cpp "*.cpp")

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" dirname ${dirname})

set(my_list add_item_ch7  avg_price_ch7) # depend on "Sales_data.h"

foreach(f IN LISTS cpp)
    get_filename_component(target ${f} NAME_WE)
    if ("${target}" IN_LIST my_list)
       add_executable("${target}" "${f}" "Sales_data.h")
    else()
       add_executable("${target}" "${f}")
    endif()
    set_target_properties("${target}" PROPERTIES OUTPUT_NAME "${target}" FOLDER "${dirname}")
endforeach()

