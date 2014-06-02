#!/bin/sh
set -xv

for d in "${@}"
do
    (
        mkdir -p "${d}"/gcc "${d}"/clang
        cp a.cpp CMakeLists.txt "${d}"

        (
            cd "${d}"/gcc
            CC=/opt/local/bin/gcc-mp-4.9
            CXX=/opt/local/bin/g++-mp-4.9
            cmake ..
            make
        )

        (
            cd "${d}"/clang
            CC=/opt/local/bin/clang-mp-4.9
            CXX=/opt/local/bin/clang++-mp-4.9
            cmake ..
            make
        )
    )
done

