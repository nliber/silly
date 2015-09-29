#!/bin/sh
set -xv

gnu_version="${GNU_VERSION:-5}"
clang_version="${CLANG_VERSION:-""}"

for d in "${@}"
do (
    mkdir -p "${d}"
    cp a.cpp CMakeLists.txt "${d}"
    cd "${d}"

    for g in ${gnu_version}
    do (
        mkdir -p "gcc${g}"
        cd "gcc${g}"
        CC="/usr/local/bin/gcc-${g}" CXX="/usr/local/bin/g++-${g}" cmake ..
        make
    ) done

    for c in ""
    do (
        mkdir -p "clang${c}"
        cd "clang${c}"
        CC="/usr/bin/clang${c}" CXX="/usr/bin/clang++${c}" cmake ..
        make
    ) done
) done

