#!/bin/bash
set -xv

gnu_version="${GNU_VERSION:-"10"}"
clang_version="${CLANG_VERSION:-"10"}"

make="${MAKE:-"make"}"
shopt -s nocasematch
case "${make}" in
    *ninja*)
        generator_name="${GENERATOR_NAME:-"Eclipse CDT4 - Ninja"}"
        job="0"
        ;;
    *make*)
        generator_name="${GENERATOR_NAME:-"Eclipse CDT4 - Unix Makefiles"}"
        job=""
        ;;
esac

cmake_options="-D CMAKE_EXPORT_COMPILE_COMMANDS=ON"

eclipse_product_version="$(fgrep -m 1 -s -h "version=" "/Applications/Eclipse.app/Contents/Eclipse/.eclipseproduct")"
eclipse_product_version="${eclipse_product_version#"version="}"
if [[ -n "${eclipse_product_version}" ]]
then
    cmake_options="${cmake_options} -D CMAKE_ECLIPSE_VERSION=${eclipse_product_version}"
fi

files="a.cpp main.cpp CMakeLists.txt"

for d in "${@}"
do (
    mkdir -p "${d}"
    cp -npv ${files} "${d}"
    cd "${d}"
    chmod -v +w ${files}

    for g in ${gnu_version}
    do (
        mkdir -p "gcc${g}"
        echo "gcc${g}/" >> ".gitignore"
        cd "gcc${g}"
        bin="/usr/local/gcc/bin"
        CC="${bin}/gcc-${g}" CXX="${bin}/g++-${g}" cmake ${cmake_options} -G "${generator_name}" ..
        ${make} -j ${job}
    )& done

    for c in ${clang_version}
    do (
        mkdir -p "clang${c}"
        echo "clang${c}/" >> ".gitignore"
        cd "clang${c}"
        #clang_root="/usr/local/clang+llvm-${c}-x86_64-apple-darwin"
        clang_root="/usr/local/clang"
        CC="${clang_root}/bin/clang" CXX="${clang_root}/bin/clang++" cmake ${cmake_options} -D "CLANG_LINK_DIRECTORIES:PATH=${clang_root}/lib" -G "${generator_name}" ..
        ${make} -j ${job}
    )& done

    wait

    git init
    git add --verbose .

    while read -r
    do
        compilation_database="${REPLY}compile_commands.json"
        if [[ -r "${compilation_database}" ]]
        then
            ln -s "${compilation_database}" .
            echo "compile_commands.json" >> ".gitignore"
            break
        fi
    done < ".gitignore"

    git add --verbose ".gitignore"
    git commit --verbose --allow-empty-message --no-edit

) done

