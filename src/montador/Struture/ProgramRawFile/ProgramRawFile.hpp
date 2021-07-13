//
// Created by Ricardo Santos on 13/07/21.
//

#ifndef COMPILER_PROGRAMRAWFILE_HPP
#define COMPILER_PROGRAMRAWFILE_HPP

#include <vector>

#include "FileLine.hpp"
#include "../Section/Section.hpp"

typedef struct ProgramRawFile {
    std::string name;
    Section header;
    Section data;
    Section text;
} Program;

#endif //COMPILER_PROGRAMRAWFILE_HPP
