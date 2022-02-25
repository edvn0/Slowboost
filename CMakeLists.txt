cmake_minimum_required(VERSION 3.21)
project(SlowboostAll)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(SlowboostAll CG_DEBUG msse2)

add_subdirectory(lib)
add_subdirectory(Slowboost)
add_subdirectory(SlowboostDemo)
add_subdirectory(SlowboostTests)
