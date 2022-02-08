# 'tests' is the subproject name
project(cg_test_suite)

# 'googletest' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'cg_test_suite' is the target name 'test1.cpp tests2.cpp' are source files
# with tests
add_executable(cg_test_suite test_main.cpp softmax_test.cpp)
target_link_libraries(cg_test_suite gtest gtest_main Slowboost)
target_include_directories(
        cg_test_suite PRIVATE ../cg/include ../cg/src /usr/local/Cellar
        /usr/local/include)
