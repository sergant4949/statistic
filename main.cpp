#include <iostream>
#include "TextHandler.h"

int main(int argc, char const *argv[]) {
    
    if ( argc < 2 ) {
        std::cout << "Text file parser. Format usage:" << std::endl;
        std::cout << "Parser inputFile [outputFile]" << std::endl;
        return 0;
    }
    
    std::ifstream inFile(argv[1]);
    if ( !inFile.is_open() ) {
        std::cout << "Unable to open input file <" << argv[1] << ">" << std::endl;
        return 0;
    }
    
    TextHandler* handler = new TextHandler();
    handler->parseText(inFile);
    
    if ( argc > 2 ) {
        std::ofstream outFile(argv[2]);
        if ( !outFile.is_open() ) {
            std::cout << "Unable to open output file <" << argv[2] << ">" << std::endl;
            inFile.close();
            return 0;
        }
        outFile << *handler << std::endl;
    } else {
        std::cout << *handler << std::endl;
    }

    return 0;
}