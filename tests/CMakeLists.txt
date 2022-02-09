# 'tests' is the subproject name
project(cg_test_suite)

# 'googletest' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE includes CONFIGURE_DEPENDS "*.hpp")

# 'cg_test_suite' is the target name 'test1.cpp tests2.cpp' are source files
# with tests
add_executable(cg_test_suite ${sources} ${includes} helpers.hpp glorot_test.cpp)
target_link_libraries(cg_test_suite PRIVATE Slowboost gtest gtest_main)
target_include_directories(
  cg_test_suite PRIVATE ../Slowboost/include ../Slowboost/src /usr/local/Cellar
                        /usr/local/include)
