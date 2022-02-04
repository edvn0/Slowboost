cmake_minimum_required(VERSION 3.21)
project(comp_graph)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(comp_graph CG_DEBUG)

add_executable(comp_graph
        comp_graph/src/main.cpp
        comp_graph/src/Node.cpp
        comp_graph/include/Node.hpp
        comp_graph/src/Operation.cpp
        comp_graph/include/Operation.hpp
        comp_graph/src/Variable.cpp
        comp_graph/include/Variable.hpp
        comp_graph/include/common.hpp
        comp_graph/include/types.hpp
        comp_graph/src/ops/Add.cpp
        comp_graph/include/ops/Add.hpp
        comp_graph/include/Placeholder.hpp
        comp_graph/include/Session.hpp
        comp_graph/src/Session.cpp
        comp_graph/include/ops/MatrixMultiply.hpp
        comp_graph/src/Placeholder.cpp
        comp_graph/src/Graph.cpp
        comp_graph/include/Graph.hpp
        comp_graph/src/ops/MatrixMultiply.cpp comp_graph/src/ops/Sigmoid.cpp comp_graph/include/ops/Sigmoid.hpp comp_graph/src/ops/Tanh.cpp comp_graph/include/ops/Tanh.hpp comp_graph/include/util/Stopwatch.hpp comp_graph/src/ops/Softmax.cpp comp_graph/include/ops/Softmax.hpp)
target_include_directories(comp_graph PRIVATE comp_graph/include /usr/local/Cellar /usr/local/include)