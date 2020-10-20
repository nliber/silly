extern int Main(int /* argc */, char const*const /* argv */[]);

#include <cstdio>   // Bug workaround -- put this before <cstdlib>

#include <cstdlib>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <typeinfo>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <cstddef>

#include <new>
#include <memory>
#include <scoped_allocator>

#include <climits>
#include <cfloat>
#include <limits>

#include <exception>
#include <stdexcept>
#include <cassert>
#include <cerrno>

#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#include <string>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include <algorithm>

#include <iterator>

#include <cmath>
#include <complex>
#include <valarray>
#include <numeric>

#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
// #include <strstream>    // deprecated
#include <iomanip>
#include <streambuf>
// #include <cstdio>    // Bug workaround -- put this before <cstdlib>

#include <locale>
#include <clocale>

#if __cplusplus >= 201103L
#include <typeindex>
#include <type_traits>
#include <chrono>
#include <initializer_list>
#include <tuple>
#include <cstdint>
#include <cinttypes>
#include <system_error>
#if __cplusplus >= 201703L && __has_include(<cuchar>)
#include <cuchar>   // C++11 header but don't have __has_include until C++17
#endif
#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <ratio>
#include <cfenv>
#if __cplusplus < 201703L
#include <codecvt>
#endif
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#endif  // C++11

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif  // C++14

#if __cplusplus >= 201703L
#include <any>
#include <optional>
#include <variant>
#if __has_include(<memory_resource>)
#include <memory_resource>
#endif
#include <string_view>
#include <charconv>
#if __has_include(<execution>)
//#include <execution>  // Doesn't compile under gcc w/o TBB
#endif
#include <filesystem>
#endif  // C++17

#if __cplusplus > 201703L
#if __has_include(<concepts>) && defined(__cpp_lib_concepts) && __cpp_lib_concepts >= 202002L
#include <concepts>
#endif
#if __has_include(<coroutine>) && __cpp_lib_coroutine >= 201902L
#include <coroutine>
#endif
#if __has_include(<compare>) // && __cpp_lib_three_way_comparison >= 201907L
#include <compare>
#endif
#include <version>
#if __has_include(<source_location>) && __cpp_lib_source_location >= 201907L
#include <source_location>
#endif
#if __has_include(<format>) && __cpp_lib_format >= 201907L
#include <format>
#endif
#if __has_include(<span>) // && __cpp_lib_span >= 202002L
#include <span>
#endif
#if __has_include(<ranges>) && __cpp_lib_ranges >= 201911L
#include <ranges>
#endif
#include <bit>
#if __has_include(<numbers>) && __cpp_lib_math_constants >= 201907L
#include <numbers>
#endif
#if __has_include(<syncstream>) && __cpp_lib_syncbuf >= 201803L
#include <syncstream>
#endif
#if __has_include(<stop_token>) && __cpp_lib_jthread >= 201911L
#include <stop_token>
#endif
#if __has_include(<semaphore>) && defined(__cpp_lib_semaphore) && __cpp_lib_semaphore >= 201907L
#include <semaphore>
#endif
#if __has_include(<latch>) && defined(__cpp_lib_latch) && __cpp_lib_latch >= 201907L
#include <latch>
#endif
#if __has_include(<barrier>) && defined(__cpp_lib_barrier) && __cpp_lib_barrier >= 201907L
#include <barrier>
#endif
#endif  // C++20



int Main(int /* argc */, char const*const /* argv */[])
{
    return 0;
}

