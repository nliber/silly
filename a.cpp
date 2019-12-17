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
#include <limits>

#include <exception>
#include <stdexcept>
#include <cassert>
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

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
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
#include <codecvt>      // deprecated C++17



#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __has_include(<filesystem>)
#include <filesystem>
#endif

#if __cplusplus >= 201103L
#include <typeindex>
#include <type_traits>
#include <chrono>
#include <initializer_list>
#include <tuple>
#include <cstdint>
#include <cinttypes>
#include <system_error>
//#include <cuchar>
#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <ratio>
#include <cfenv>
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#endif  // C++11

#if __cplusplus >= 201402L
#endif  // C++14

#if __cplusplus >= 201703L
#endif  // C++17

#if __cplusplus > 201703L
#endif  // C++20




int Main(int /* argc */, char const*const /* argv */[])
{
    return 0;
}

