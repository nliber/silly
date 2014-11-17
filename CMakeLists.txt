cmake_minimum_required (VERSION 2.6)
project (a.out)
add_executable(a.out a.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")

set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Weverything")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-c++98-compat")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-c++98-compat-pedantic")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-padded")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -fcolor-diagnostics")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -fdiagnostics-format=vi")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -fdiagnostics-show-category=name")

set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wall")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wextra")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wno-unused-local-typedefs")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -fdiagnostics-color")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_CLANG_FLAGS}")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_GNU_FLAGS}")
endif()

include_directories(SYSTEM "/site/apps/boost")
include_directories("/Users/nliber/git/cpp-infrastructure/ccruft/src/main/")

