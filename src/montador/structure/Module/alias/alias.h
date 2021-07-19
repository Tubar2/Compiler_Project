//
// Created by Ricardo Santos
//

#ifndef COMPILER_ALIAS_H
#define COMPILER_ALIAS_H

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

#endif //COMPILER_ALIAS_H
