//
// Created by Ricardo Santos
//

#include <iostream>
#include <vector>

#include "structure/Global_Module/Global_Module.h"
#include "utils/utils.h"


int main (int argc, char *argv[]){
    if (argc < 2 || argc > 4) {
        std::cerr << "Número de argumentos inválidos" << std::endl;
        exit(1);
    }
    // Lê cada arquivo fornecido e remove o final ".asm"
    std::vector<std::string> filenames;
    for(int i = 1; i<argc; i++) {
        filenames.emplace_back(argv[i]);
    }

    // Define the global module
    Global_Module globalModule {};
    int CFac = 0;
    for (auto & filename : filenames){
        CFac += globalModule.buildModule("/Users/ricardosantos/Developer/C++/Compiler/resource/object/" + filename + ".obj", CFac);
    }

    // Correct each module un_solved reference
    globalModule.SolveReferences();

    //
    globalModule.SolveRelatives();

    // Link each module
    globalModule.link_modules();

    // Write Final objcet to memory
    createObjectProgram(globalModule.obj_code, "/Users/ricardosantos/Developer/C++/Compiler/resource/link/" + filenames[0] + ".obj");

    return 0;
}


