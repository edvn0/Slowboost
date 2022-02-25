#! /usr/bin/env sh

pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd > /dev/null
}

set -e

build_target() {
    local build_type="$2"
    local target="$1"
    build_folder="build/$build_type"
    if ! [ -d $build_folder ];
    then
        mkdir -p $build_folder
    fi;

    pushd $build_folder
    if ! [ -a "build.ninja" ];
    then
        cmake ../.. -G Ninja -DCMAKE_BUILD_TYPE=$build_type
    fi;

    ninja $1
    popd
}

start_target() {
    pushd $build_folder
    pushd $1
    
    ./$1 "$@"
 
    popd
    popd
}

TARGET="${1:-SlowboostDemo}"
BUILD_TYPE="${2:-Debug}"

found_build_type=0
for t in {"Debug","Default","MinSizeRel","Release","RelWithDebInfo"};
do
    if [ "$t" == "$BUILD_TYPE" ];
    then
        found_build_type=1
        break
    fi;
done

found_target=0
for t in {"Slowboost","SlowboostDemo","SlowboostTests"};
do
    if [ "$t" == "$TARGET" ];
    then
        found_target=1
        break
    fi;
done


if [ "$found_build_type" -eq 1 ] && [ "$found_target" -eq 1 ];
then
    tgt="$TARGET"
    build_target "$TARGET" "$BUILD_TYPE"
    shift 2
    start_target "$tgt" "$@"
else
    if ! [ "$found_build_type" -eq 1 ];
    then
        echo "Build mode \"$BUILD_TYPE\" not applicable. \nAccepted are: 'Debug', 'Default', 'MinSizeRel', 'Release' and 'RelWithDebInfo'"
        exit 1
    fi;

    if ! [ "$found_target" -eq 1 ];
    then
        echo "Target \"$TARGET\" not applicable. \nAccepted are: 'Slowboost', 'SlowboostDemo' and 'SlowboostTests'"
        exit 1
    fi;
fi;

