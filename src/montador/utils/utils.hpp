//
// Created by Ricardo Santos
//

#ifndef COMPILER_UTILS_HPP
#define COMPILER_UTILS_HPP

#include "../structure/Instruction/Instruction.hpp"
#include "../structure/ProgramRawFile/ProgramRawFile.hpp"
#include "../structure/Module/Module.h"

std::string removeExtension(const char * s);

ProgramRawFile * readRawIntoModule(const std::string& filename);

bool checkForErrors(Module & module);

void writeToObjFile(std::vector<int> &vector, Module &module);

#endif //COMPILER_UTILS_HPP
