extern int Main(int /* argc */, char const*const /* argv */[]);

#include <cstdlib>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <chrono>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#if __cplusplus >= 201703L && __has_include(<any>)
#include <any>
#endif
#if __cplusplus >= 201703L && __has_include(<optional>)
#include <optional>
#endif
#if __cplusplus >= 201703L && __has_include(<variant>)
#include <variant>
#endif

#include <new>
#include <memory>
#include <scoped_allocator>
#if __has_include(<memory_resource>)
# include <memory_resource>
#endif

#include <climits>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <limits>

#include <exception>
#include <stdexcept>
#include <cassert>
#include <system_error>
#include <cerrno>

#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwchar>
#if __has_include(<cuchar>)
#include <cuchar>
#endif
#include <string>
#if __cplusplus >= 201703L
#include <string_view>
#endif

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

#include <algorithm>
#if 0
#if __has_include(<execution>)
#include <execution>
#endif
#endif

#include <iterator>

#include <cmath>
#include <complex>
#include <valarray>
#include <random>
#include <numeric>
#include <ratio>
#include <cfenv>

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
#include <cstdio>

#include <locale>
#include <clocale>
#include <codecvt>      // deprecated C++17

#include <regex>

#include <atomic>

#include <thread>
#include <mutex>
#if __cplusplus >= 201402L
#include <shared_mutex>
#endif
#include <future>
#include <condition_variable>

#if __has_include(<filesystem>)
#include <filesystem>
#endif

int Main(int /* argc */, char const*const /* argv */[])
{
    return 0;
}

