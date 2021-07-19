//
// Created by Ricardo Santos
//

#ifndef COMPILER_PROGRAMRAWFILE_HPP
#define COMPILER_PROGRAMRAWFILE_HPP

#include <vector>
#include <string>

#include "FileLine.hpp"
#include "../Section/Section.hpp"

typedef struct ProgramRawFile {
    std::string name;
    Section header;
    Section data;
    Section text;

    bool has_end = false;
} Program;

#endif //COMPILER_PROGRAMRAWFILE_HPP
