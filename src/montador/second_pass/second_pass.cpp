//
// Created by Ricardo Santos
//

#include "second_pass.h"

Object_Code secondPass(Module & m){
    Object_Code obj_file {};

    // Process Text
    for (auto & instruction : m.text_code){
        auto text_obj_file = m.processTextVariables(instruction, obj_file.size());
        obj_file.insert(obj_file.end(),
                        text_obj_file.begin(),
                        text_obj_file.end());
    }

    // Process Data
    for (auto & instruction : m.data_code){
        auto data_obj_file = m.processDataVariables(instruction, obj_file.size());
        obj_file.insert(obj_file.end(),
                        data_obj_file.begin(),
                        data_obj_file.end());
    }

    return obj_file;
}