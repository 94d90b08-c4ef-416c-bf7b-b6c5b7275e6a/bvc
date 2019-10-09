#include <iostream>
#include <docopt.h>
#include <map>


// class CliParser {
// private:
//     std::string USAGE;
//     std::map<std::string, docopt::value> parsed_args;
// private:
//     void parse_args() {

//     }

// public:
//     CliParser(){
//         USAGE = R"(
// 		Usage:
//                   bvc init
//                   bvc add <filename>
//                   bvc (co | checkout) <fff>
//                   bvc (-v | --version)
//                   bvc (-h | --help)

//                 Options:
//                   -h --help       Show this help.
//                   -v --version    Show wersion.
//                 )";
//     }
//     CliParser(const CliParser& parser) = delete;
//     CliParser& operator=(const CliParser&) = delete;

//     // void operator()(std::vector<std::string> args) {
//     //     parsed_args = docopt::docopt(USAGE, args, true, "bvc 1.0");
//     //     parse_args();
//     // }

//     std::map<std::string, docopt::value> &&operator()(std::vector<std::string> args) {
//         std::map<std::string, docopt::value> parsed_args = docopt::docopt(USAGE, args, true, "bvc 1.0");
//         return std::move(parsed_args);
//     }
//     // std::string GetUsage() {
//     //     return USAGE;
//     // }

// };

static const char USAGE[] =
R"(BVC.

    Usage:
	   bvc [--bvc-dir=<dir>] <command> [<args>...]

    Options:
      -h --help        Show this screen.
      -v --version     Show version.
      --bvc-dir=<dir>  Path to .bvc/.
)";

int main(int argc, const char** argv)
{
    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc },
                         true,               // show help if requested
                         "bvc 1.0");  // version string

    for(auto const& arg : args) {
        std::cout << arg.first <<  " " << arg.second << std::endl;
    }

    return 0;
}


// int main(int argc, char** argv) {

//     CliParser cli_parser;
//     auto values = cli_parser({ argv + 1, argv + argc });

//     std::map<std::string, docopt::value> parsed_args = docopt::docopt(cli_parser.GetUsage(), { argv + 1, argv + argc }, true, "bvc 1.0");

//     for(auto const& arg : parsed_args) {
//         std::cout << arg.first <<  arg.second << std::endl;
//     }
// }
