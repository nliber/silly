#include <iostream>

extern int Main(int argc, char const*const argv[]);

namespace {
    struct Args
    {
        explicit Args(char const*const argv[]) : _argv(argv) {}
        
        friend std::ostream& operator<<(std::ostream& os, Args const&& that)
        {
            for (auto argv = that._argv; *argv; ++argv)
                os << argv << ' ';

            return os;
        }

    private:
        char const*const* _argv;
    };
} // namespace

int main(int argc, char* argv[])
{
	try { return Main(argc, argv); }
    catch (std::exception const& e)
    {
        std::cerr << Args(argv) << ' ' << __PRETTY_FUNCTION__ << " std::exception: " << e.what() << std::endl; 
        return 1;
    }
    catch (...)
    {
        std::cerr << Args(argv) << ' ' << __PRETTY_FUNCTION__ << " unknown exception" << std::endl; 
        return 255;
    }
}
