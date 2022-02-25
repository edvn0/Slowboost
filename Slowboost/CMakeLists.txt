cmake_minimum_required(VERSION 3.21)
project(Slowboost)

set(CMAKE_CXX_STANDARD 20)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE includes CONFIGURE_DEPENDS "*.hpp")

add_library(Slowboost ${sources} ${includes})
target_link_libraries(
  Slowboost PRIVATE xtensor xtensor-blas xtl ${BLAS_LIBRARIES}
                    ${LAPACK_LIBRARIES} spdlog)
target_compile_definitions(Slowboost PUBLIC SLOWBOOST_DEBUG)
target_include_directories(
  Slowboost PUBLIC include ../lib/xtensor-blas/include ../lib/xtl/include
                   ../lib/xtensor/include ../lib/spdlog/include)
