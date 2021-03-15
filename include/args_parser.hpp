#pragma once

#include <string>
#include <map>
#include <stdexcept>

class ArgsParser {
    public:
        ArgsParser(int argc, char *argv[]);
        bool exists(std::string paramName);
        std::string get(std::string paramName);
        unsigned count(void);
    private:
        std::map<std::string, std::string> _args;
};