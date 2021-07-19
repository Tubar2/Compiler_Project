//
// Created by Ricardo Santos
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Program/Program.h"

int main(int argc, char *argv[]) {
    // Checks for correct number of arguments
    if (argc < 1) {
        std::cerr << "Número de argumentos inválidos" << std::endl;
        exit(1);
    }
    // Lê cada arquivo fornecido
    std::string filename = argv[1];

    // Abrindo arquivo objeto para leitura
    std::ifstream file {"/Users/ricardosantos/Developer/C++/Compiler/resource/link/" + filename + ".obj"};
    if (!file) {
        // Arquivo não encotrado
        std::cerr << "Erro ao abrir arquivo" << std::endl;
        std::exit(1);
    }

    std::string line;
    int num {};
    std::vector<int> memory{};
    // Lendo a linha do arquivo
    std::getline(file, line);
    std::istringstream iss {line};
    while (iss >> num){
        memory.push_back(num);
    }


    Program program {memory, "/Users/ricardosantos/Developer/C++/Compiler/resource/out/"+filename+".out" };
    program.run();

    std::cout << "End of Simulation" << std::endl;
}