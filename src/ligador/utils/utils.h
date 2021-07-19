//
// Created by Ricardo Santos
//

#ifndef COMPILER_UTILS_H
#define COMPILER_UTILS_H

#include <string>
#include <vector>

std::string removeExtension(const char * s);

void createObjectProgram(const std::vector<int> &objCode, std::string filename);

#endif //COMPILER_UTILS_H
