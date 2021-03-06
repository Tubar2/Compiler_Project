//
// Created by Ricardo Santos
//

#ifndef COMPILER_INSTRUCTION_HPP
#define COMPILER_INSTRUCTION_HPP

#include <vector>

// Defines line pointer, eg.: `label: ...`
typedef std::string Label;

// Defines program behavior
typedef std::string Operation;

// Defines the behavior's parameters
typedef std::vector<std::string> Operands;

//typedef int Instruction_Line;

typedef struct Instruction {
    Label label;
    Operation operation;
    Operands operands;
    int instructionLine;

    inline bool isEmpty() const { return (label.empty() && operation.empty()); }
    inline bool isSection() const { return (operation == "section"); }
    inline bool isHeader() const { return (operation == "begin" || operation == "extern" || operation == "public" || operation == "end") ;}
} Instruction;

#endif //COMPILER_INSTRUCTION_HPP
