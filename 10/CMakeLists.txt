file(GLOB cpp "*.cpp")

get_filename_component(dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" dirname ${dirname})

include_directories(../6)

foreach(f IN LISTS cpp)
    get_filename_component(target ${f} NAME_WE)
    add_executable("${target}" "${f}")
    set_target_properties("${target}" PROPERTIES OUTPUT_NAME "${target}" FOLDER "${dirname}")
endforeach()

