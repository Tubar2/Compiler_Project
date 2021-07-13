//
// Created by Ricardo Santos on 13/07/21.
//

#ifndef COMPILER_FILELINE_HPP
#define COMPILER_FILELINE_HPP

#include <vector>

typedef struct FileLine {
    std::vector<std::string> tokens;
    int line;
    bool has_end = false;
} ProgramLine;

#endif //COMPILER_FILELINE_HPP
