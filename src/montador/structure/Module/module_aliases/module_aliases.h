//
// Created by Ricardo Santos on 14/07/21.
//

#ifndef COMPILER_MODULE_ALIASES_H
#define COMPILER_MODULE_ALIASES_H

#include <string>
#include <vector>

#include "../../../structure/Instruction/Instruction.hpp"

typedef struct Symbol_Use_Case {
    std::string label;
    int addr;
} Symbol_Use_Case;

// Estrutura auxilar para identificar se o símbolo é externo
typedef struct Value {
    int addr;
    bool isExtern;
} Value;


typedef struct Header {
    std::string name;
    std::string bit_map;
} Header;

typedef std::vector<Instruction> Instruction_Set;

#endif //COMPILER_MODULE_ALIASES_H
