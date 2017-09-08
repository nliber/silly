extern int Main(int argc, char const*const argv[]);

#include <boost/exception/diagnostic_information.hpp>
#include <boost/date_time/local_time/local_time.hpp>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

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

