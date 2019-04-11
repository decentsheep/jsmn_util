cmake_minimum_required(VERSION 3.5.1)

project(jsmn_util)

add_library(libjsmn STATIC IMPORTED)
set_property(TARGET libjsmn PROPERTY IMPORTED_LOCATION ../jsmn/libjsmn.a)

include_directories(BEFORE ./jsmn)
include_directories(BEFORE ./inc)
add_definitions(-DJSMN_PARENT_LINKS)
add_compile_options(-g3)


add_custom_target(jsmn COMMAND make clean && make CFLAGS=-DJSMN_PARENT_LINKS WORKING_DIRECTORY ../jsmn)
add_custom_target(example_cnn_json COMMAND cp ../example/cnn/example_cnn.json .)
add_library(json_util STATIC src/jsmn_util.c src/json_tree.c src/json_query.c)
add_executable(example_cnn example/cnn/example_cnn.c)
add_dependencies(example_cnn jsmn example_cnn_json)
target_link_libraries(example_cnn json_util libjsmn)
