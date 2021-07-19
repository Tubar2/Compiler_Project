//
// Created by Ricardo Santos
//

#ifndef COMPILER_FILELINE_HPP
#define COMPILER_FILELINE_HPP

#include <vector>

typedef struct FileLine {
    std::vector<std::string> tokens;
    int line_number;
} ProgramLine;

#endif //COMPILER_FILELINE_HPP
