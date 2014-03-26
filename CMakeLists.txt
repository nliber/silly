cmake_minimum_required (VERSION 2.6)
project (a.out)
add_executable(a.out a.cpp)

set(CMAKE_CXX_COMPILER "/site/apps/clang/bin/clang++")
set(CMAKE_C_COMPILER "/site/apps/clang/bin/clang")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat-pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-padded")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-format=vi")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-show-category=name")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")

include_directories(SYSTEM "/site/apps/boost")
include_directories("/Users/nliber/git/cpp-infrastructure/ccruft/src/main/")

