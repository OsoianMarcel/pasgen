#include <iostream>
#include <map>

#include "pas_gen.hpp"
#include "args_parser.hpp"

int main(int argc, char *argv[]) {
	ArgsParser args(argc, argv);

	if (args.exists("-h")) {
		std::cout << "\t[CLI Password Generator]" << std::endl;
		std::cout << "-l\tPassword length (default: 32)" << std::endl;
		std::cout << "-c\tCaracter set (n: number, l: lowercase, u: uppercase, s: symbols) (default: nul)" << std::endl;
		std::cout << "-n\tNumber of passwords to generate (default: 1)" << std::endl;
		std::cout << "-h\tHelp" << std::endl;
		return 0;
	}

	PasGen PasGen;

	if (args.exists("-l")) {
		try {
			PasGen.setLength(std::stoi(args.get("-l")));
		} catch (...) {
			std::cerr << "-l shoud be a number greater than zero" << std::endl;
			return -1;
		}
	}

	if (args.exists("-c")) {
		PasGen.setUseNumbers(args.get("-c").find("n") != std::string::npos);
		PasGen.setUseLowChars(args.get("-c").find("l") != std::string::npos);
		PasGen.setUseUpChars(args.get("-c").find("u") != std::string::npos);
		PasGen.setUseSymbols(args.get("-c").find("s") != std::string::npos);
	}

	unsigned n = 1;
	if (args.exists("-n")) {
		try {
			n = std::stoi(args.get("-n"));
		} catch (...) {
			std::cerr << "-n param exception: can not convert string to number" << std::endl;
			return -1;
		}
	}
	
	try {
		for (unsigned i = 0; i < n; i++) {
			std::cout << PasGen.gen() << std::endl;
		}
	} catch (std::logic_error &e) {
		std::cerr << "Gen error: " << e.what() << std::endl;
		return -1;
	} catch (...) {
		std::cerr << "Can not generate password" << std::endl;
		return -1;
	}

    return 0;
}