#include <ccruft/cool/Out.h>
#include <ccruft/cool/pretty_name.h>

#include <boost/exception/diagnostic_information.hpp>

#include <algorithm>
#include <fstream>
#include <list>
#include <regex>
#include <tuple>
#include <array>
#include <functional>
#include <locale>
#include <scoped_allocator>
#include <type_traits>
#include <atomic>
#include <future>
#include <map>
#include <set>
#include <typeindex>
#include <bitset>
#include <initializer_list>
#include <memory>
#include <sstream>
#include <typeinfo>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <stack>
#include <unordered_map>
//#include <codecvt>
#include <ios>
#include <new>
#include <stdexcept>
#include <unordered_set>
#include <complex>
#include <iosfwd>
#include <numeric>
#include <streambuf>
#include <utility>
#include <condition_variable>
#include <iostream>
#include <ostream>
#include <string>
#include <valarray>
#include <deque>
#include <istream>
#include <queue>
//#include <strstream>
#include <vector>
#include <exception>
#include <iterator>
#include <random>
#include <system_error>
#include <forward_list>
#include <limits>
#include <ratio>
#include <thread>

#include <cassert>
#include <cinttypes>
#include <csignal>
#include <cstdio>
#include <cwchar>
#include <ccomplex>
#include <ciso646>
//#include <cstdalign>
#include <cstdlib>
#include <cwctype>
#include <cctype>
#include <climits>
#include <cstdarg>
#include <cstring>
#include <cerrno>
#include <clocale>
#include <cstdbool>
#include <ctgmath>
#include <cfenv>
#include <cmath>
#include <cstddef>
#include <ctime>
#include <cfloat>
#include <csetjmp>
#include <cstdint>
//#include <cuchar>

extern int Main(int argc, char const*const argv[]);

namespace {
    struct Args
    {
        explicit Args(char const*const argv[]) : _argv(argv) {}
        
        friend std::ostream& operator<<(std::ostream& os, Args const&& that)
        {
            const char* space = "";
            for (auto argv = that._argv; *argv; ++argv)
            {
                os << space << *argv;
                space = " ";
            }

            return os;
        }

    private:
        char const*const* _argv;
    };
} // namespace

int main(int argc, char* argv[])
{
	try { return Main(argc, argv); }
    catch (...)
    {
        std::cerr << Args(argv) << '\n'
                << __PRETTY_FUNCTION__ << '\n'
                << boost::current_exception_diagnostic_information() << std::endl;
        return 1;
    }
}

int Main(int /* argc */, char const*const /* argv */[])
{
    return 0;
}

