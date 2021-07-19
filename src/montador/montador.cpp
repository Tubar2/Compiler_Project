#include <iostream>
#include <vector>

#include "utils/utils.hpp"
#include "structure/ProgramRawFile/ProgramRawFile.hpp"
#include "first_pass/first_pass.h"
#include "second_pass/second_pass.h"

#define IN_CLION false

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
        rawModules.push_back(readRawIntoModule("resource/test/" + filename +  ".asm"));
    }
    filenames.clear();

    // Process each module with the first pass algorithm
    std::vector<Module> modules;
    modules.reserve(rawModules.size());
    for (auto module : rawModules){
        modules.push_back(firstPass(module));
    }
    rawModules.clear();

    // Turn each module into it's object code
    std::vector<Object_Code> codes;
    codes.reserve(modules.size());
    for (auto & module : modules){
        codes.push_back(secondPass(module));
    }

    // Check for errors
    for (auto & module : modules){
        if (checkForErrors(module)) return 0;
    }

    // Write object code to file
    for (int i =0;i<modules.size(); i++) {
        writeToObjFile(codes[i], modules[i]);
    }

    std::cout << "Files Assembled" << std::endl;
    return 0;
}
