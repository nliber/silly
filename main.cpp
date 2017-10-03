extern int Main(int argc, char const*const argv[]);

#include <boost/exception/diagnostic_information.hpp>
#include <cool/Args.h>
#include <cool/chrono.h>
#include <chrono>
#include <iostream>

namespace {

    class Stopwatch
    {
        using clock = std::chrono::high_resolution_clock;
        using time_point = clock::time_point;

        static time_point now() { return clock::now(); }

    public:
        using nanoseconds = std::chrono::nanoseconds;

        nanoseconds lap() const noexcept
        { return std::chrono::duration_cast<nanoseconds>(now() - start); }

    private:
        time_point start = now();
    };

} // namespace

int main(int argc, char* argv[])
{
    using cool::chrono::system_clock::operator<<;
    using cool::chrono::duration::operator<<;

    std::cerr
        << "Built " <<  __FILE__ << " on " << __DATE__ << ' ' << __TIME__
        << "\nStarted " << cool::Args(argv)
        << " at " << std::chrono::system_clock{}
        << std::endl;

    Stopwatch sw;
    int status;
	try { status = Main(argc, argv); }
    catch (...)
    {
        std::cerr << cool::Args(argv) << '\n'
                << __PRETTY_FUNCTION__ << '\n'
                << boost::current_exception_diagnostic_information() << std::endl;
        status = 1;
    }

    std::cerr
        << "Stopped " << cool::Args(argv)
        << " at " << std::chrono::system_clock{}
        << " (" << sw.lap()
        << ") with status=" << status
        << std::endl;

    return status;
}

