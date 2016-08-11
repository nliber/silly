#!/bin/sh
set -xv

gnu_version="${GNU_VERSION:-6}"
clang_version="${CLANG_VERSION:-"3.8"}"

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
        CC="/usr/local/bin/gcc-${g}" CXX="/usr/local/bin/g++-${g}" cmake ..
        make
    ) done

    for c in ""
    do (
        mkdir -p "clang${c}"
        echo "clang${c}/" >> ".gitignore"
        cd "clang${c}"
        CC="/usr/bin/clang${c}" CXX="/usr/bin/clang++${c}" cmake ..
        make
    ) done

    git init
    git add --verbose .
    git commit --verbose --allow-empty-message --no-edit

) done

