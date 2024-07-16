#include "Parser/Parser.hpp"
#include "Code/Code.hpp"
#include <iostream>
#include <string>
#include <fstream>


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
//            std::cout << code.dest(parser.currentCommand) << code.comp(parser.currentCommand) <<  code.jump(parser.currentCommand) << std::endl;


            
        }
    
    
    return 0;
}