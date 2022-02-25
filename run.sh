#! /usr/bin/env sh

pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd > /dev/null
}

set -e

build_app() {
    build_folder="build/$1"
    if ! [ -d $build_folder ];
    then
        mkdir -p $build_folder
    fi;

    pushd $build_folder
    if ! [ -a "build.ninja" ];
    then
        cmake ../.. -G Ninja -DCMAKE_BUILD_TYPE=$1
    fi;

    ninja SlowboostDemo
    popd
}

start_app() {
    pushd $build_folder
    pushd SlowboostDemo
    
    ./SlowboostDemo "$@"
 
    popd
    popd
}

BUILD_TYPE="${1:-Debug}"

found=0
for t in {"Debug","Default","MinSizeRel","Release","RelWithDebInfo"};
do
    if [ "$t" == "$BUILD_TYPE" ];
    then
        found=1
        break
    fi;
done

if [ "$found" -eq 1 ];
then
    build_app "$BUILD_TYPE"
    shift
    start_app "$@"
else
    echo "Build mode \"$BUILD_TYPE\" not applicable. \nAccepted are: 'Debug', 'Default', 'MinSizeRel', 'Release' and 'RelWithDebInfo'"
fi;

