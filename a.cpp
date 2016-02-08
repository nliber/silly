#include <boost/exception/diagnostic_information.hpp>
#include <boost/date_time/local_time/local_time.hpp>

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

#ifdef __clang__
#include <boost/utility/string_ref.hpp>
namespace std { namespace experimental {
    template<typename charT, typename traits = std::char_traits<charT>>
    using basic_string_view = boost::basic_string_ref<charT, traits>;

    using string_view       = basic_string_view<char>;
    using u16string_view    = basic_string_view<char16_t>;
    using u32string_view    = basic_string_view<char32_t>;
    using wstring_view      = basic_string_view<wchar_t>;
} /* experimental namespace */ } /* std namespace */
#else
#include <experimental/string_view>
#endif

extern int Main(int argc, char const*const argv[]);

namespace {

    class Args
    {
    public:
        explicit Args(std::vector<std::string> vs)
            : args{ std::move(vs) }
        {
            argvs.reserve(args.size() + 1);
            std::transform(std::begin(args), std::end(args), std::back_inserter(argvs), [](std::string const& s) { return s.c_str(); });
            argvs.emplace_back();
        }

        template<typename InputIterator>
        Args(InputIterator first, InputIterator last)
            : Args{ std::vector<std::string>(std::move(first), std::move(last)) }
        {
        }

        explicit Args(int c, const char*const v[])
            : Args{ v, v + c }
        {
        }

        explicit Args(const char*const v[])
            : Args{ v, [v]() mutable { while(*v) ++v; return v; }() }
        {
        }

        Args(Args const& that)
            : Args{ that.args }
        {
        }

        Args(Args&& that)
            : args{ std::move(that.args) }
            , argvs{ std::move(that.argvs) }
        {
            that = Args{ std::vector<std::string>{} };
        }

        ~Args() = default;

        friend void swap(Args& lhs, Args& rhs) noexcept
        {
            using namespace std;
            swap(lhs.args, rhs.args);
            swap(lhs.argvs, rhs.argvs);
        }

        Args& operator=(Args that) noexcept
        {
            swap(*this, that);
            return *this;
        }

        int argc()               const noexcept { return static_cast<int>(args.size()); }
        const char*const* argv() const noexcept { return argvs.data(); }

        friend std::ostream& operator<<(std::ostream& os, Args const& that)
        {
            const char* space = "";
            for (auto&& a : that.args)
            {
                os << space << a;
                space = " ";
            }
            return os;
        }

    private:
        std::vector<std::string> args;
        std::vector<const char*> argvs;
    };

} // namespace

int main(int argc, char* argv[])
{
    auto started = boost::posix_time::microsec_clock::local_time();
    std::cerr
        << "Built " <<  __FILE__ << " on " << __DATE__ << ' ' << __TIME__
        << "\nStarted " << Args(argv)
        << " at " << started
        << std::endl;

    int status;
	try { status = Main(argc, argv); }
    catch (...)
    {
        std::cerr << Args(argv) << '\n'
                << __PRETTY_FUNCTION__ << '\n'
                << boost::current_exception_diagnostic_information() << std::endl;
        status = 1;
    }

    auto stopped = boost::posix_time::microsec_clock::local_time();
    std::cerr
        << "Stopped " << Args(argv)
        << " at " << stopped
        << " (duration: " << (stopped - started)
        << ") with status=" << status
        << std::endl;

    return status;
}

int Main(int /* argc */, char const*const /* argv */[])
{
    return 0;
}

