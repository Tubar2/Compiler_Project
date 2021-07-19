//
// Created by Ricardo Santos
//

#ifndef COMPILER_AUX_H
#define COMPILER_AUX_H

#include <string>

#include "../../Instruction/Instruction.hpp"
#include "../../ProgramRawFile/FileLine.hpp"

std::string processLabel(std::string & label);

Instruction toInstruction(FileLine & line);


#endif //COMPILER_AUX_H
