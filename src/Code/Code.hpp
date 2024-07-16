#ifndef CODE_H
#define CODE_H
#include <string>

class Code {
    public:
        std::string dest(std::string &mnemonic);
        std::string comp(std::string &mnemonic);
        std::string jump(std::string &mnemonic);
};

#endif