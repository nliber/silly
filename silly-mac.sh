#!/bin/bash
set -xv

#gnu_version="${GNU_VERSION:-"11"}"
#clang_version="${CLANG_VERSION:-"11"}"

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
    if [[ -e "${d}" ]]
    then
        printf "%q exists; ABORTING!" "${d}" >&2
        exit 1
    fi

    mkdir -p "${d}"
    cp -npv ${files} "${d}"
    cd "${d}"
    chmod -v +w ${files}

    for gccroot in "${HOMEBREW_PREFIX}"/opt/gcc "${HOMEBREW_PREFIX}"/opt/gcc@*
    do (
        version="$(readlink "${gccroot}")"
        version="${version##*/}"
        version="${version%_*}"
        major="${version%%.*}"
        cxx="${gccroot}"/bin/g++-"${major}"
        cc="${gccroot}"/bin/gcc-"${major}"
        build=gcc-"${version}"

        mkdir -p "${build}"
        echo "${build}"/ >> .gitignore

        if [[ "${gccroot##*/}" == gcc ]]
        then
            ln -s "${build}"/ gcc
            echo gcc >> .gitignore
        fi

        cd "${build}"
        CC="${cc}" CXX="${cxx}" cmake ${cmake_options} -G "${generator_name}" ~-
        ${make} -j ${job}

    )& done

    for clangroot in "${HOMEBREW_PREFIX}"/opt/llvm "${HOMEBREW_PREFIX}"/opt/llvm@*
    do (
        version="$(readlink "${clangroot}")"
        version="${version##*/}"
        version="${version%%_*}"
        major="${version%%.*}"
        cxx="${clangroot}"/bin/clang++
        cc="${clangroot}"/bin/clang
        build=clang-"${version}"

        mkdir -p "${build}"
        echo "${build}"/ >> .gitignore

        cd "${build}"
        CC="${cc}" CXX="${cxx}" cmake ${cmake_options} -D "CLANG_LINK_DIRECTORIES:PATH=${clang_root}/lib" -G "${generator_name}" ~-
        ${make} -j ${job}
    )& done

    (
        cxx=/usr/bin/clang++
        version="$("${cxx}" --version)"
        version="${version#*(}"
        version="${version%%)*}"
        build="${version}"

        mkdir -p "${build}"
        echo "${build}"/ >> .gitignore

        ln -s "${build}"/ clang
        echo clang >> .gitignore

        cd "${build}"
        CC="${cc}" CXX="${cxx}" cmake ${cmake_options} -G "${generator_name}" ~-
        ${make} -j ${job}

    )&

    wait

    # Create symlink for compilecommands
    compilecommands="compile_commands.json"
    for build in clang gcc clangapple clang* gcc*
    do
        if [[ -r "${build}"/"${compilecommands}" ]]
        then
            ln -s "${build}"/"${compilecommands}" "${compilecommands}"
            echo "${compilecommands}" >> .gitignore
            break
        fi
    done

    git init --initial-branch "${d}"
    git add --verbose .
    git commit --verbose --allow-empty-message --no-edit

) done

