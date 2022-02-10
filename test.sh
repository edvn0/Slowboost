#! /usr/bin/env sh

set -e

test_project() {
  cd tests || exit
  cmake --build "$(pwd)/../cmake-build-debug" --target cg_test_suite
  "$(pwd)/../cmake-build-debug/tests/cg_test_suite" --gtest_color=no
}

test_project