cmake_minimum_required(VERSION 3.21)
project(Slowboost)

set(CMAKE_CXX_STANDARD 20)

add_library(
        Slowboost
        src/Node.cpp
        include/Node.hpp
        src/Operation.cpp
        include/Operation.hpp
        src/Variable.cpp
        include/Variable.hpp
        include/common.hpp
        include/types.hpp
        src/ops/Add.cpp
        include/ops/Add.hpp
        include/Placeholder.hpp
        include/Session.hpp
        src/Session.cpp
        include/ops/MatrixMultiply.hpp
        src/Placeholder.cpp
        src/Graph.cpp
        include/Graph.hpp
        src/ops/MatrixMultiply.cpp
        src/ops/Sigmoid.cpp
        include/ops/Sigmoid.hpp
        src/ops/Tanh.cpp
        include/ops/Tanh.hpp
        include/util/Stopwatch.hpp
        src/ops/Softmax.cpp
        include/ops/Softmax.hpp
        src/ops/Log.cpp
        include/ops/Log.hpp
        src/ops/Hadamard.cpp
        include/ops/Hadamard.hpp
        src/ops/ReduceSum.cpp
        include/ops/ReduceSum.hpp
        src/ops/Negative.cpp
        include/ops/Negative.hpp
        include/util/CSVImport.hpp
        src/ops/LeakyRelu.cpp
        include/ops/LeakyRelu.hpp)
target_include_directories(Slowboost PRIVATE include /usr/local/include)
