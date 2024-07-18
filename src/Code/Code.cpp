#include "Code.hpp"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string Code::dest(std::string &mnemonic)
{
    // std::cout << mnemonic;
    std::unordered_map<std::string, std::string> destMap = {
        {"null", "000"},
        {"M", "001"},
        {"D", "010"},
        {"MD", "011"},
        {"A", "100"},
        {"AM", "101"},
        {"AD", "110"},
        {"AMD", "111"},
        {"test","test"}};
    auto it = destMap.find(mnemonic);
    if (it != destMap.end())
    {
        return it->second;
    }
    else
    {
        return "000";
    }
}

std::string Code::comp(std::string &mnemonic) {
    std::unordered_map<std::string, std::string> compMap = {
        {"0", "101010"},
        {"1", "111111"},
        {"-1", "111010"},
        {"D", "001100"},
        {"A", "110000"},
        {"!D", "001101"},
        {"!A", "110001"},
        {"-D", "001111"},
        {"-A", "110011"},
        {"D+1", "011111"},
        {"A+1", "110111"},
        {"D-1", "001110"},
        {"A-1", "110010"},
        {"D+A", "000010"},
        {"D-A", "010011"},
        {"A-D", "000111"},
        {"D&A", "000000"},
        {"D|A", "010101"},
        {"M", "110000"},
        {"!M", "110001"},
        {"-M", "110011"},
        {"M+1", "110111"},
        {"D+M", "000010"},
        {"D-M", "010011"},
        {"M-D", "000111"},
        {"D&M", "000000"},
        {"D|M", "010101"},
        {"test","test"}
    };

    std::unordered_map<std::string, std::string> aone{{"M", "110000"}, {"!M", "110001"}, {"-M", "110011"}, {"M+1", "110111"}, {"M-1", "110010"}, {"D+M", "000010"}, {"D-M", "010011"}, {"M-D", "000111"}, {"D&M", "000000"}, {"D|M", "010101"},{"test","test"}};

    auto it = compMap.find(mnemonic);
    auto it2 = aone.find(mnemonic);
    if (it != compMap.end() || it2 != aone.end()) {
    
        if (it2 != aone.end())
        {
            return "1" + it2->second;
        }
        else
        {
            return "0" + it->second;
        }
    } else
    {
        return mnemonic + "-> Not supported";
    }
}

std::string Code::jump(std::string &mnemonic)
{
    std::unordered_map<std::string, std::string> jumpMap = {
        {"null", "000"},
        {"JGT", "001"},
        {"JEQ", "010"},
        {"JGE", "011"},
        {"JLT", "100"},
        {"JNE", "101"},
        {"JLE", "110"},
        {"JMP", "111"},
        {"test","test"}};
    auto it = jumpMap.find(mnemonic);
    if (it != jumpMap.end())
    {
        return it->second;
    }
    else
    {
        return "000";
    }
}