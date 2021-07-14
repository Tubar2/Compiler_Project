//
// Created by Ricardo Santos on 13/07/21.
//

#include "first_pass.h"


Module firstPass(ProgramRawFile * p){
    Module module{p->name};

    // Process each section of the program
    module.processHeader(p->header);
    int posCounter = module.processText(p->text);
    module.processData(p->data, posCounter);


    return module;
}

