//
// Created by Ricardo Santos
//

#include "aux.h"


std::string processLabel(std::string & label) {
    label.pop_back();   // Removes ':'
    return label;
}

Instruction toInstruction(FileLine & line){
    Instruction instruction;
    for (auto & token : line.tokens) {
        // token is a label
        if (token.find(':') != std::string::npos){
            instruction.label = processLabel(token);
        } else {
            //  Token is part of the operation
            if (instruction.operation.empty()){
                instruction.operation = token;
            } else {
                instruction.operands.push_back(token);
            }
        }
    }
    return instruction;
}