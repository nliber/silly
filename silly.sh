#!/bin/sh
set -xv

gnu_version="${GNU_VERSION:-5}"
clang_version="${CLANG_VERSION:-3.6}"

for d in "${@}"
do (
    mkdir -p "${d}"
    cp a.cpp CMakeLists.txt "${d}"
    cd "${d}"

    for g in ${gnu_version}
    do (
        mkdir -p "gcc${g}"
        cd "gcc${g}"
        CC="/opt/local/bin/gcc-mp-${g}" CXX="/opt/local/bin/g++-mp-${g}" cmake ..
        make
    ) done

    for c in ${clang_version}
    do (
        mkdir -p "clang${c}"
        cd "clang${c}"
        CC="/opt/local/bin/clang-mp-${c}" CXX="/opt/local/bin/clang++-mp-${c}" cmake ..
        make
    ) done
) done

