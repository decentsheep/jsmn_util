cmake_minimum_required(VERSION 3.5.1)

project(jsmn_util)

add_library(libjsmn STATIC IMPORTED GLOBAL)
set_property(TARGET libjsmn PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/jsmn/libjsmn.a)

include_directories(BEFORE ./jsmn)
include_directories(BEFORE ./inc)
add_definitions(-DJSMN_PARENT_LINKS)
add_compile_options(-g3)


add_custom_target(jsmn COMMAND make clean && make CFLAGS=-DJSMN_PARENT_LINKS WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/jsmn)
add_dependencies(libjsmn jsmn)
add_custom_target(example_cnn_json COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/example/cnn/example_cnn.json .)
add_library(jsmn_util STATIC src/jsmn_util.c src/json_tree.c src/json_query.c)
add_executable(example_cnn example/cnn/example_cnn.c)
add_dependencies(example_cnn jsmn example_cnn_json)
target_link_libraries(example_cnn jsmn_util libjsmn)
