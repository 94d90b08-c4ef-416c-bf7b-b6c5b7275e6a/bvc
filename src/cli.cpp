#include <iostream>
#include <docopt.h>
#include <map>


class CliParser {
private:
    std::string USAGE;
public:
    CliParser(){
        USAGE = R"(Usage:
                    bvc init
                    bvc add <filename>
                    bvc (co | checkout) <fff>
                    bvc (-v | --version)
                    bvc (-h | --help)

                Options:
                    -h --help       Show this help.
                    -v --version    Show wersion.
                )";
    }
    CliParser(const CliParser& parser) = delete;
    CliParser& operator=(const CliParser&) = delete;

    std::map<std::string, docopt::value> &&operator()(std::vector<std::string> args) {
        std::map<std::string, docopt::value> parsed_args = docopt::docopt(USAGE, args, true, "bvc 1.0");
        return std::move(parsed_args);
    }
    std::string GetUsage() {
        return USAGE;
    }

};


int main(int argc, char** argv) {

    CliParser cli_parser;
    auto values = cli_parser({ argv + 1, argv + argc });

    std::map<std::string, docopt::value> parsed_args = docopt::docopt(cli_parser.GetUsage(), { argv + 1, argv + argc }, true, "bvc 1.0");
    return 0;
}
