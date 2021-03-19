#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <math.h>

class PasGen;

typedef char (PasGen::*PasGenRandFn)();

class PasGen {
    public:
        PasGen(unsigned long userSeed = 0);
        
        std::string gen(void);

        void setLength(unsigned short length);
        void setUseSymbols(bool yes);
        void setUseNumbers(bool yes);
        void setUseUpChars(bool yes);
        void setUseLowChars(bool yes);
    private:
        unsigned short _length = 32;
        bool _useSymbols = false;
        bool _useNumbers = true;
        bool _useLowChars = true;
        bool _useUpChars = true;
        std::mt19937 _mt19937_gen;

        unsigned short _rand(unsigned short min, unsigned short max);
        void _shuffleRandomFuncs(PasGenRandFn fns[], unsigned short count);
        
        char _randomSymbol(void);
        char _randomNumber(void);
        char _randomUpChar(void);
        char _randomLowChar(void);
};