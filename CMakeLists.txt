cmake_minimum_required (VERSION 2.6)
project (a.out)
find_package(Threads REQUIRED)
SET(BOOST_ROOT "/usr/local/Cellar/boost/1.61.0")
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} ${BOOST_ROOT}/include)
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${BOOST_ROOT}/lib)
find_package(Boost 1.61.0
    COMPONENTS
        atomic
        chrono
        container
        context
        coroutine
        date_time
        exception
        filesystem
        graph
        iostreams
        locale
        log
        log_setup
        math_c99
        math_c99f
        math_c99l
        math_tr1
        math_tr1f
        math_tr1l
        prg_exec_monitor
        program_options
        #python
        random
        regex
        serialization
        signals
        system
        test_exec_monitor
        thread
        timer
        unit_test_framework
        wave
        wserialization
    REQUIRED)
add_executable(a.out a.cpp)
target_link_libraries(a.out
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")

# Sanitizers
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize-undefined-trap-on-error")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=thread")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=integer-divide-by-zero")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=unreachable")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=vla-bound")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=null")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=return")
set(CMAKE_CXX_SANITIZER_FLAGS "${CMAKE_CXX_SANITIZER_FLAGS} -fsanitize=signed-integer-overflow")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_SANITIZER_FLAGS}")

set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Weverything")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-c++98-compat")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-c++98-compat-pedantic")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-padded")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-date-time")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -Wno-unused-member-function")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -fcolor-diagnostics")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -fdiagnostics-format=vi")
set(CMAKE_CXX_CLANG_FLAGS "${CMAKE_CXX_CLANG_FLAGS} -fdiagnostics-show-category=name")

set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wall")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wextra")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wno-unused-local-typedefs")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -fdiagnostics-color")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -Og")
set(CMAKE_CXX_GNU_FLAGS "${CMAKE_CXX_GNU_FLAGS} -fsanitize=undefined")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_CLANG_FLAGS}")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_GNU_FLAGS}")
endif()

