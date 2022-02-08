cmake_minimum_required(VERSION 3.21)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(${ProjectId} CG_DEBUG)

add_subdirectory(lib)
add_subdirectory(Slowboost)
add_subdirectory(SlowboostDemo)
add_subdirectory(tests)
