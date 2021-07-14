#include <iostream>
#include <vector>

#include "utils/utils.hpp"
#include "structure/ProgramRawFile/ProgramRawFile.hpp"
#include "first_pass/first_pass.h"


int main(int argc, char *argv[]) {
    // Checks for correct number of arguments
    if (argc < 2) {
        std::cerr << "Número de argumentos inválidos" << std::endl;
        exit(1);
    }

    // Reads user filename inputs and removes extension
    std::vector<std::string> filenames;
    for(int j = 1; j<argc; j++) {
        filenames.push_back(removeExtension(argv[j]));
    }

    // Read each file and store it in memory
    std::vector<ProgramRawFile *> rawModules;
    rawModules.reserve(filenames.size());
    for (auto & filename : filenames) {
        rawModules.push_back(readRawIntoModule("/Users/ricardosantos/Developer/C++/Compiler/src/montador/resource/test/" + filename +  ".asm"));
    }

    // Process each module with the first pass algorithm
    std::vector<Module> modules;
    modules.reserve(rawModules.size());
    for (auto module : rawModules){
        modules.push_back(firstPass(module));
    }
    std::cout << "End Program" << std::endl;
    return 0;
}
