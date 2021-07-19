//
// Created by Ricardo Santos
//

#ifndef COMPILER_MODULE_H
#define COMPILER_MODULE_H

#include <vector>
#include <map>
#include <string>

#include "alias/alias.h"

class Module {
public:
    int correction_factor{};
    std::string filename;

    std::string bit_map;

    std::vector<Use_Case> uses_table;

    std::vector<int> semi_obj_code {};

    /* CONSTRUCTOR */
    explicit Module(const std::string & filename);
};


#endif //COMPILER_MODULE_H
