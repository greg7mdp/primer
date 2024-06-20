file(GLOB cpp "*.cpp")

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" dirname ${dirname})

foreach(f IN LISTS cpp)
    get_filename_component(target ${f} NAME_WE)
    add_executable("${target}_${dirname}" "${f}")
    set_target_properties("${target}_${dirname}" PROPERTIES OUTPUT_NAME "${target}")
endforeach()

