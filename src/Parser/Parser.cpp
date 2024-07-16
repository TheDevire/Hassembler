#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Parser::Parser(const std::string &filename) {
    inputFile.open(filename);
    std::string line;
    

}

bool Parser::hasMoreCommands() {
    return static_cast<bool>(std::getline(inputFile,currentCommand));

    }

std::string Parser::advance() {
    return "test";
}

std::string Parser::removeWhitespaces(std::string& str) {
    std::string out ;
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    return str;

    
}
CommandType Parser::commandType( ) {
    if (isACommand(currentCommand) == 1) {
        return A_COMMAND;
    } else if ( isCCommand(currentCommand)) {
        return C_COMMAND;
    } else if ( isLCommand(currentCommand)) {
        return L_COMMAND;
    }
    return INVALID_COMMAND;
}

bool Parser::isACommand(std::string& command) {
    return (!command.empty() && command[0] == '@');
}

bool Parser::isCCommand(std::string& command) {
    if (!command.empty()) {
        if (command.find('=') != std::string::npos) {
            return true;
        } else if ( command.find(';') != std::string::npos) {
            return true;
        }
        return false;
    }
    return false;
}

bool Parser::isLCommand(std::string& command) {
    return (!command.empty() && command[0] == '(' && command.back() == ')');
}

std::string Parser::dest() {
    std::vector<std::string> deststring{"null","M","D","MD","A","AM","AD","AMD"};
    std::vector<std::string>::iterator it;
    if (isCCommand(currentCommand)) {
       if ( currentCommand.find(";") != std::string::npos)  {
            return "null";
        
       } else if ( currentCommand.find("=") != std::string::npos) {
            size_t found = currentCommand.find("=");
            std::string s = currentCommand.substr(0,found);
            it = std::find(deststring.begin(), deststring.end(),s);
            if (it != deststring.end()) {
                return s;

            }
            return "null";
    }
       }
    return "";   

}


std::string Parser::comp() {
    std::vector<std::string> compstring{"0","1","-1","D","A","!D","!A","-D","-A","D+1","D-1","A+1","A-1","D+A","D-A","A-D","D&A","D|A","M","!M","-M","M+1","M-1","D+M","D-M","M-D","D&M","D|M"};
    std::vector<std::string>::iterator it;
    if (isCCommand(currentCommand) == 1) {
        if (currentCommand.find('=') != std::string::npos) {
            size_t found = currentCommand.find("=");
            std::string s = currentCommand.substr(found+1);
            it = std::find(compstring.begin(),compstring.end(),s);
            if (it != compstring.begin()) {
                return removeWhitespaces(s); 

            }
       } else if (currentCommand.find(";") != std::string::npos) { 
            size_t found = currentCommand.find(";");
            std::string s = currentCommand.substr(0,found);
            it = std::find(compstring.begin(),compstring.end(),s);
            if (it != compstring.end()) {
                return s;
            }
              } 
    } 
    return "";
}

std::string Parser::jump()  {
    std::vector<std::string> jumpstring{"null","JGT","JEQ","JGE","JLT","JNE","JLE","JMP"};
    std::vector<std::string>::iterator it;
    if (isCCommand(currentCommand) == 1) {
        if (currentCommand.find(";") != std::string::npos) {
            size_t found = currentCommand.find(";");
            std::string s = currentCommand.substr(found+1);
            it = std::find(jumpstring.begin(),jumpstring.end(),s); 
        if (it != jumpstring.end()) {
            return s;
        }
    }

}

    return "";
}