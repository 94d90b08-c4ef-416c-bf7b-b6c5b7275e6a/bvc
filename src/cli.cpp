#include <iostream>
#include <docopt.h>
#include <map>

class CliParser {
private:
    std::string USAGE;
    std::map<std::string, docopt::value> parsed_args;
private:
    void parse_args() {
      for(const auto &[key, values] : parsed_args) {
        std::cout << key <<  " " << values << std::endl;
    	}
    }

public:
    CliParser(){
      USAGE =
          R"(Usage: bvc [--bvc-dir=<dir>] <command> [<args>...]

            Options:
              -h --help        Show this screen.
              -v --version     Show version.
              --bvc-dir=<dir>  Path to .bvc/.
          )";
    }
    CliParser(const CliParser& parser) = delete;
    CliParser& operator=(const CliParser&) = delete;

    void operator()(std::vector<std::string> args) {
      parsed_args = docopt::docopt(USAGE, args, true, "bvc 1.0");
      parse_args();
    }
};


 int main(int argc, char** argv) {

     CliParser cli_parser;
     cli_parser({ argv + 1, argv + argc });


 }
