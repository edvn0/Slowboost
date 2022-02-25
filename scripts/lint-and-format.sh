#! /usr/bin/env sh

set -e

lint() {
  cmake-format ../CMakeLists.txt ../SlowboostTests/CMakeLists.txt ../SlowboostDemo/CMakeLists.txt ../Slowboost/CMakeLists.txt -i
  cmake-lint --disabled-codes C0113 ../CMakeLists.txt ../SlowboostTests/CMakeLists.txt ../SlowboostDemo/CMakeLists.txt ../Slowboost/CMakeLists.txt
}

format() {
  find ../Slowboost -name "*.cpp" -type f -exec clang-format -style=file -i {} \;
  find ../Slowboost -name "*.hpp" -type f -exec clang-format -style=file -i {} \;
  find ../SlowboostDemo -name "*.cpp" -type f -exec clang-format -style=file -i {} \;
  find ../SlowboostDemo -name "*.hpp" -type f -exec clang-format -style=file -i {} \;
  find ../SlowboostTests -name "*.cpp" -not -path "../test/googletest/*" -type f -exec clang-format -style=file -i {} \;
  find ../SlowboostTests -name "*.hpp" -not -path "../test/googletest/*" -type f -exec clang-format -style=file -i {} \;
}

lint_and_format() {
    cd "$(dirname "$0")"
    lint
    format
    cd -
}

lint_and_format
