#include "pas_gen.hpp"

static const char SYMBOLS[] = "!\";#$%&'()*+,-./:;<=>?@[]^_`{|}~";

PasGen::PasGen(unsigned long userSeed) {
    std::random_device rd;

    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
            ).count() +
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
            ).count() +
        (std::mt19937::result_type)userSeed
    );

    std::mt19937 gen(seed);

    _mt19937_gen = gen;
}

std::string PasGen::gen(void) {
    std::string result;

    unsigned short countFns = 0;
    unsigned short countUsedFns = 0;
    PasGenRandFn randFns[4];

    if (_useNumbers) {
        randFns[countFns++] = &PasGen::_randomNumber;
    }
    if (_useLowChars) {
        randFns[countFns++] = &PasGen::_randomLowChar;
    }
    if (_useUpChars) {
        randFns[countFns++] = &PasGen::_randomUpChar;
    }
    if (_useSymbols) {
        randFns[countFns++] = &PasGen::_randomSymbol;
    }

    if (countFns == 0) {
        throw std::logic_error("Use at least one character set (numbers, uppercase, lowercase, symbols)");
    }

    _shuffleRandomFuncs(randFns, countFns);

    std::uniform_int_distribution<unsigned> distrib(0, countFns - 1);

    unsigned short remLen = _length;
    unsigned short rf;
    unsigned short mustUseEvery = _length > countFns ? (unsigned short)std::floor((double)_length / countFns) : 1;
    while (remLen > 0) {
        if (countFns != countUsedFns && remLen % mustUseEvery == 0) {
            rf = countUsedFns++;
        } else {
            rf = distrib(_mt19937_gen);
        }
        
        result += (this->*randFns[rf])();
        remLen--;
    }

    return result;
}

void PasGen::setLength(unsigned short length) {
    if (length <= 0) {
        throw std::invalid_argument("Length must be greater than zero");
    }

    _length = length;
}

void PasGen::setUseNumbers(bool yes) {
    _useNumbers = yes;
}

void PasGen::setUseLowChars(bool yes) {
    _useLowChars = yes;
}

void PasGen::setUseUpChars(bool yes) {
    _useUpChars = yes;
}

void PasGen::setUseSymbols(bool yes) {
    _useSymbols = yes;
}

unsigned short PasGen::_rand(unsigned short min, unsigned short max) {
    return min + _mt19937_gen() % (max + 1 - min);
}

char PasGen::_randomSymbol(void) {
    return SYMBOLS[_rand(0, sizeof(SYMBOLS) - 2)];
}

char PasGen::_randomNumber(void) {
    return (char)_rand(48, 57);
}

char PasGen::_randomUpChar(void) {
     return (char)_rand(65, 90);
}

char PasGen::_randomLowChar(void) {
    return (char)_rand(97, 122);
}

void PasGen::_shuffleRandomFuncs(PasGenRandFn fns[], unsigned short count) {
    unsigned short j;
    PasGenRandFn tempFn;
    for (unsigned short i = count - 1; i > 0; i--) {
        j = _rand(0, i);

        tempFn = fns[i];
        fns[i] = fns[j];
        fns[j] = tempFn;
    }
}