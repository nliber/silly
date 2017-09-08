#!/bin/sh
set -xv

gnu_version="${GNU_VERSION:-"7.2 7.1"}"
clang_version="${CLANG_VERSION:-"5.0 xcode"}"

for d in "${@}"
do (
    mkdir -p "${d}"
    cp a.cpp CMakeLists.txt "${d}"
    cd "${d}"

    for g in ${gnu_version}
    do (
        mkdir -p "gcc${g}"
        echo "gcc${g}/" >> ".gitignore"
        cd "gcc${g}"
        CC="/usr/local/gcc-${g}/bin/gcc-${g}" CXX="/usr/local/gcc-${g}/bin/g++-${g}" cmake ..
        make
    ) done

    for c in ${clang_version}
    do (
        mkdir -p "clang${c}"
        echo "clang${c}/" >> ".gitignore"
        cd "clang${c}"
        CC="/usr/local/bin/clang-${c}" CXX="/usr/local/bin/clang++-${c}" cmake ..
        make
    ) done

    git init
    git add --verbose .
    git commit --verbose --allow-empty-message --no-edit

) done

