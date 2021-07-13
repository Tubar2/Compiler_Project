//
// Created by Ricardo Santos on 13/07/21.
//

#ifndef COMPILER_SECTION_HPP
#define COMPILER_SECTION_HPP

#include <vector>

typedef struct Section {
    std::vector<FileLine> lines;
} Section;

#endif //COMPILER_SECTION_HPP
