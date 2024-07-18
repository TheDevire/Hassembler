#include "Parser/Parser.hpp"
#include "Code/Code.hpp"
#include "SymbolTable/SymbolTable.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>


void firstPass(std::string &filename,SymbolTable& symboltable,Parser& parser);
void secondpass(std::string &filename,SymbolTable& symboltable,Parser& parser,Code& code);


int main(int argc , char* argv[]) {

    std::string filename; // store filename from argv
    // checking arguments
    if (argc > 2)  {
        std::cerr << " Give only 1 flie " << std::endl;
    } else if ( argc < 2 ) {
        std::cerr  << "Give filename" << std::endl;
    } else {
        filename = argv[1];
    }
 //   std::ifstream asmfile(filename); // file to read 
 //   std::string filedata((std::istreambuf_iterator<char>(asmfile)),std::istreambuf_iterator<char>()); // read first to last and store it to filedata as string https://stackoverflow.com/a/27407136

    Parser parser(filename); // Give the stream to parser constructor
    Code code;
    SymbolTable symboltable;

    firstPass(filename,symboltable,parser);
    secondpass(filename,symboltable,parser,code);
/*
    std::string binaryout;
    while(parser.hasMoreCommands()) {
        if (parser.commandType() == 1)  {
            std::string dest =  parser.dest() ;
            std::string comp = parser.comp();
            std::string jump = parser.jump();

            std::string destout = code.dest(dest);
            std::string compout = code.comp(comp);
            std::string jumpout = code.jump(jump);
            std::cout << "111" << compout << destout<< jumpout << std::endl;
        }
    }
    */
    
   
//            std::cout << code.dest(parser.currentCommand) << code.comp(parser.currentCommand) <<  code.jump(parser.currentCommand) << std::endl;


            
        //}
    
    
    return 0;
}

void firstPass(std::string &filename,SymbolTable& symboltable,Parser& parser) {
    std::ifstream textfile;
    textfile.open(filename);
    std::string cmd;

    int romAddress = 0 ;
    std::string modstr;
    while ( std::getline(textfile,cmd)) {
        if (parser.isLCommand(cmd)) {
            for ( int i = 0;i < cmd.size(); i++) {
                if ( cmd[i] != '(' && cmd[i] != ')') {
                    modstr += cmd[i];       
                }
            }
            symboltable.addEntry(modstr, romAddress);
        } else if ( parser.isACommand(cmd) || parser.isCCommand(cmd)) {
            romAddress++;
        }
    }

    }
    
void secondpass(std::string &filename,SymbolTable& symboltable,Parser& parser, Code& code) {
    int ramaddres = 16;

    // output file
    std::ofstream outputfile;
    outputfile.open("prog.hack");
    while (parser.hasMoreCommands()) {
        // for A-Command
        std::string cmd = parser.currentCommand;
        int pos = cmd.find('/') ;
        
        if (parser.isACommand(cmd)) {

            std::string symbol =cmd.substr(cmd.find("@")+1 );
            if (symboltable.contains(symbol)) {
                std::string binary = std::bitset<15>(symboltable.GetAddress(symbol)).to_string();
                outputfile << '0' << binary << '\n';
            } else {
                if (isdigit(symbol[0])) {
                    std::string binary = std::bitset<15>(std::stoi(symbol)).to_string();
                    outputfile << '0' << binary << '\n';
                } else {
                    symboltable.addEntry(symbol,ramaddres);
                    std::string binary = std::bitset<15>(ramaddres).to_string();
                    outputfile << '0' << binary << '\n';
                    ramaddres++;
                }
            } // for C-Command
        } else if (parser.isCCommand(cmd)) {
            std::string dest =  parser.dest() ;
            std::string comp = parser.comp();
            std::string jump = parser.jump();

            std::string destout = code.dest(dest);
            std::string compout = code.comp(comp);
            std::string jumpout = code.jump(jump);
            outputfile << "111" << compout << destout<< jumpout << std::endl;
        }


    }
}


// std::string removePar(std::string &str, char *chartoremove) {
//     std::string modified;
//     for ( int i =0 ; i < str.size(); i++) {
//         if (str[i] != chartoremove) {
//             modified += str[i];
//         } 
//     }
//     return modified;

// }