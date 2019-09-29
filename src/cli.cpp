#include <iostream>
#include <docopt.h>
#include <map>

static std::string USAGE = 
R"(BVC.

    Usage:
        bvc init
        bvc add <filename>
        bvc (co | checkout) <fff>
        bvc (-v | --version)
        bvc (-h | --help)
    
    Options:
        -h --help       Show this help.
        -v --version    Show wersion.
    )";

class CliParser {
private:
    std::string USAGE;
    CliParser(){
        USAGE = R"(BVC.

                    Usage:
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

public:
    static CliParser& CreateParser() {
        static CliParser single_parser;
        return single_parser;
    }
    // std::map<std::string, docopt::value> operator()(std::vector<std::string> args) {
    //     std::map<std::string, docopt::value> args = docopt::docopt(this->USAGE, args, true, "bvc 1.0");
    //     //return args;
    // }
};

//g++ -o cli src/cli.cpp -std=c++17 -I\\C:\Users\amotaylo\Downloads\docopt.cpp-master

// cxxopts::Options CreateParser() {
//     cxxopts::Options options("MyPrograms", "Oh Programs, my Pograms, how I love to think about you!");
//     options
//         .positional_help("[...]")
//         .show_positional_help();
//     options
//         .add_options()
//         ("init", "Init repository")
//         ("add", "Add file", cxxopts::value<std::string>()->implicit_value(""))
//         ;
//     return options;
// }

int main(int argc, char** argv) {

    std::map<std::string, docopt::value> args = docopt::docopt(USAGE, 
                                                  { argv + 1, argv + argc },
                                                  true,               // show help if requested
                                                  "Naval Fate 2.0");  // version string

    // for(auto const& arg : args) {
    //     std::cout << arg.first << ": " << arg.second << std::endl;
    // }

    // std::vector<std::string> arg;
    // auto cli_parser = CliParser::CreateParser;
    // cli_parser(arg);
    
    // auto parser = CreateParser();
    // auto results = parser.parse(argc, argv);

    // if(results.count("add")) {
    //     std::cout << results["add"].as<std::string>() << "\n";
    // }

    std::cout << "hello cli";
    return 0;
}