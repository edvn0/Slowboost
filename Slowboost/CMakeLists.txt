cmake_minimum_required(VERSION 3.21)
project(Slowboost)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE includes CONFIGURE_DEPENDS "*.hpp")

message(STATUS "${sources}")

add_library(Slowboost ${sources} ${includes} include/util/Enumerate.hpp)
target_include_directories(Slowboost PRIVATE include /usr/local/include
        ../lib/EigenRand)
