//
// Created by Ricardo Santos
//

#ifndef COMPILER_GLOBAL_MODULE_H
#define COMPILER_GLOBAL_MODULE_H

#include <vector>
#include <map>

#include "../Module/Module.h"

class Global_Module {
public:
    std::vector<Module *> Modules {};

    std::vector<int> obj_code {};

    Global_Definitions globalDefinitions {};

    std::vector<std::string> errorsList {};

    int buildModule(const std::string &filename, int correction_factor);

    Global_Definitions *ReadObj(const std::string &filename, int correction_factor);

    void SolveReferences();

    void NewError(std::string error, const std::string &token);

    void SolveRelatives();

    void link_modules();
};


#endif //COMPILER_GLOBAL_MODULE_H
