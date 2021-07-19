//
// Created by Ricardo Santos
//

#ifndef COMPILER_SECTION_HPP
#define COMPILER_SECTION_HPP

#include <vector>

#include "../ProgramRawFile/FileLine.hpp"

typedef struct Section {
    std::vector<FileLine> lines;
} Section;

#endif //COMPILER_SECTION_HPP
