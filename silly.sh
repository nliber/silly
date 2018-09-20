#!/bin/bash
set -xv

gnu_version="${GNU_VERSION:-"8.2"}"
clang_version="${CLANG_VERSION:-"7"}"
#gnu_version="${GNU_VERSION:-"7.2 7.1"}"
#clang_version="${CLANG_VERSION:-"5.0 xcode"}"

make="${MAKE:-"make"}"
shopt -s nocasematch
case "${make}" in
    *ninja*)
        generator_name="${GENERATOR_NAME:-"Eclipse CDT4 - Ninja"}"
        ;;
    *make*)
        generator_name="${GENERATOR_NAME:-"Eclipse CDT4 - Unix Makefiles"}"
        ;;
esac

cmake_options="-D CMAKE_EXPORT_COMPILE_COMMANDS=ON"

eclipse_product_version="$(fgrep -m 1 -s -h "version=" "${HOME}/eclipse/cpp-photon/Eclipse.app/Contents/Eclipse/.eclipseproduct" "/opt/eclipse/.eclipseproduct")"
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
        CC="/usr/local/gcc-${g}/bin/gcc-${g}" CXX="/usr/local/gcc-${g}/bin/g++-${g}" cmake ${cmake_options} -G "${generator_name}" ..
        ${make} -j
    )& done

    for c in ${clang_version}
    do (
        mkdir -p "clang${c}"
        echo "clang${c}/" >> ".gitignore"
        cd "clang${c}"
        CC="/usr/local/bin/clang-${c}" CXX="/usr/local/bin/clang++-${c}" cmake ${cmake_options} -G "${generator_name}" ..
        ${make} -j
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

