//
// Created by Ricardo Santos
//

#include <fstream>
#include <iostream>

#include "utils.h"

void createObjectProgram(const std::vector<int> &objCode, std::string filename) {
    std::ofstream out_file {filename, std::ios::trunc};
    if (!out_file){
        std::cerr << "Error creating exit file " << filename << std::endl;
        exit(1);
    } else {
        for (auto code : objCode){
            out_file << code << " ";
        }
        out_file << "\n";
    }
}