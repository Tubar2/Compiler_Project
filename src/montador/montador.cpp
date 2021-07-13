#include <iostream>
#include "types.hpp"

int main(int argc, char *argv[]) {

    if (argc < 2 || argc > 4) {
        std::cerr << "Número de argumentos inválidos" << std::endl;
        exit(1);
    }


    std::cout << "End Program" << std::endl;
    return 0;
}
