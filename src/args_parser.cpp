#include "args_parser.hpp"

ArgsParser::ArgsParser(int argc, char *argv[]) {
	std::string pv = "";
	for (int i = argc - 1; i >= 0; i--) {
		if (argv[i][0] == '-') {
			_args[argv[i]] = pv;
			pv = "";
		} else {
			pv = argv[i];
		}
    }
}

bool ArgsParser::exists(std::string paramName) {
    return _args.find(paramName) != _args.end();
}

std::string ArgsParser::get(std::string paramName, std::string defVal) {
	if (!exists(paramName)) {
		return defVal;
	}

    return _args[paramName];
}

unsigned ArgsParser::count(void) {
    return _args.size();
}