# 'tests' is the subproject name
project(SlowboostTests)

# 'googletest' is the folder with Google Test sources
add_subdirectory(googletest)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE includes CONFIGURE_DEPENDS "*.hpp")

add_executable(SlowboostTests ${sources} ${includes})
target_link_libraries(SlowboostTests PRIVATE Slowboost gtest gtest_main)
target_include_directories(
  SlowboostTests
  PRIVATE ../Slowboost/include
          ../Slowboost/src
          /usr/local/Cellar
          /usr/local/include
          ../lib/xtensor/include
          ${gtest_SOURCE_DIR}/include
          ${gtest_SOURCE_DIR})
