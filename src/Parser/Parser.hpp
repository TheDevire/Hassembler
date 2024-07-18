#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <fstream>

// enum for different type of command output
enum CommandType {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND,
    INVALID_COMMAND
};

class Parser {
    public: 

    // created all the members needed for it
        Parser(const std::string &filename) ;
        bool hasMoreCommands();
        CommandType commandType();
        std::string advance();
        std::string symbol();
        std::string dest();
        std::string comp();
        std::string jump();
        std::string currentCommand;

        bool isLCommand(std::string& command);
        bool isACommand(std::string& command);
        bool isCCommand(std::string& command);

        std::string removeWhitespaces(std::string& str);
    private:

        std::ifstream inputFile; 
};

#endif

