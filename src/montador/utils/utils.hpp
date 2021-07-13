//
// Created by Ricardo Santos on 13/07/21.
//

#ifndef COMPILER_UTILS_HPP
#define COMPILER_UTILS_HPP

#include "../Struture/Instruction/Instruction.hpp"
#include "../Struture/ProgramRawFile/ProgramRawFile.hpp"

std::string removeExtension(const char * s);

ProgramRawFile * readRawIntoModule(const std::string& filename);

#endif //COMPILER_UTILS_HPP
