//
// Created by Ricardo Santos
//

#ifndef COMPILER_ALIAS_H
#define COMPILER_ALIAS_H

#include <string>

class Use_Case {
public:
    std::string token;
    int addr;

public:
    Use_Case(const std::string &token, int addr) : token(token), addr(addr) {}
};

typedef std::map<std::string, int> Global_Definitions;


#endif //COMPILER_ALIAS_H
