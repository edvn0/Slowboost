cmake_minimum_required(VERSION 3.21)
set(projectid SlowboostDemo)
project(${projectid})

set(CMAKE_CXX_STANDARD 20)

add_executable(${projectid} demo.h demo.cpp)
target_include_directories(
  ${projectid} PRIVATE ../Slowboost/include ../lib/EigenRand /usr/local/Cellar
                       /usr/local/include)
target_link_libraries(${projectid} PRIVATE Slowboost)
