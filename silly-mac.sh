#!/bin/bash
#set -xv

gnu_version="${GNU_VERSION:-"11"}"
clang_version="${CLANG_VERSION:-"11"}"

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

    for gccroot in /usr/local/Cellar/gcc*/*
    do (
        cxx="$(echo "${gccroot}"/bin/g++-*)"
        version="${cxx#"${gccroot}"/bin/g++-}"
        cc="${gccroot}"/bin/gcc-"${version}"
        build=gcc"${version}"

        mkdir -p "${build}"
        echo "${build}"/ >> ".gitignore"
        cd "${build}"
        CC="${cc}" CXX="${cxx}" cmake ${cmake_options} -G "${generator_name}" ~-
        ${make} -j ${job}
    )& done

    for clangroot in /usr/local/Cellar/llvm*/*
    do (
        cxx="${clangroot}"/bin/clang++
        version="${clangroot#/usr/local/Cellar/llvm*/}"
        version="${version%%.*}"
        cc="${clangroot}"/bin/clang
        build=clang"${version}"

        mkdir -p "${build}"
        echo "${build}"/ >> ".gitignore"
        cd "${build}"
        CC="${cc}" CXX="${cxx}" cmake ${cmake_options} -D "CLANG_LINK_DIRECTORIES:PATH=${clang_root}/lib" -G "${generator_name}" ~-
        ${make} -j ${job}
    )& done

    (
        cxx=/usr/bin/clang++
        version=apple
        cc=/usr/bin/clang
        build=clangapple

        mkdir -p "${build}"
        echo "${build}"/ >> ".gitignore"
        cd "${build}"
        CC="${cc}" CXX="${cxx}" cmake ${cmake_options} -G "${generator_name}" ~-
        ${make} -j ${job}
    )&

    wait

    # Create symlink for latest gcc
    for gccroot in /usr/local/Cellar/gcc/*
    do (
        cxx="$(echo "${gccroot}"/bin/g++-*)"
        version="${cxx#"${gccroot}"/bin/g++-}"
        build=gcc"${version}"

        ln -s "${build}" gcc
        echo gcc >> ".gitignore"
    ) done

    # Create symlink for latest clang
    for clangroot in /usr/local/Cellar/llvm/*
    do (
        version="${clangroot#/usr/local/Cellar/llvm*/}"
        version="${version%%.*}"
        build=clang"${version}"

        ln -s "${build}" clang
        echo clang >> ".gitignore"

    ) done


    git init --initial-branch "${d}"
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

