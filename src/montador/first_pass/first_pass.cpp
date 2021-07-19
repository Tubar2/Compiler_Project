//
// Created by Ricardo Santos
//

#include "first_pass.h"


Module firstPass(ProgramRawFile * p){
    Module module{p->name};

    // Process each section of the program
    module.processHeader(p->header);
    int posCounter = module.processText(p->text);
    module.processData(p->data, posCounter);

    // Adjusts definitions table
    for (auto & a : module.definitionsTable){
        a.second = module.symbolsTable[a.first].addr;
    }

    return module;
}

