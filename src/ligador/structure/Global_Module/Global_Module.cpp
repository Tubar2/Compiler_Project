//
// Created by Ricardo Santos
//

#include <fstream>
#include <iostream>
#include <sstream>

#include "Global_Module.h"
#include "../../utils/utils.h"


int Global_Module::buildModule(const std::string &filename, int correction_factor) {
    auto newDefinitions = this->ReadObj(filename, correction_factor);
    this->globalDefinitions.insert(newDefinitions->begin(), newDefinitions->end());

    return this->Modules.back()->correction_factor;
}

Global_Definitions * Global_Module::ReadObj(const std::string &filename, int correction_factor) {
    // Abrindo arquivo para leitura e checando se foi aberto corretamente
    std::ifstream file {filename};
    if (!file) {
        // Arquivo não encotrado
        std::cerr << "Erro ao abrir arquivo" << std::endl;
        std::exit(1);
    }

    Module *module;
    std::string line, token, substr;     // 'Line' holds each file line; 'word' each word separated by spaces
    bool header_filename = true;
    int addr;
    auto *newGlobalDefinitions = new Global_Definitions {};
    std::istringstream iss;

    while (std::getline(file, line)) {
        switch (line[0]) {
            case 'H':
                substr = {line.begin()+3, line.end()};
                if (header_filename) {
                    module = new Module{substr};
                    header_filename = false;
                } else {
                    module->correction_factor = std::stoi(substr);
                }
                break;
            case 'R':
                substr = {line.begin()+3, line.end()};
                module->bit_map = substr;
                break;
            case 'U':
                substr = {line.begin()+3, line.end()};
                iss = std::istringstream{substr};       // string-stream para leitura
                iss >> token >> addr;
                module->uses_table.emplace_back(token, addr);
                break;
            case 'D':
                substr = {line.begin()+3, line.end()};
                iss = std::istringstream{substr};       // string-stream para leitura
                iss >> token >> addr;
                newGlobalDefinitions->insert({token, addr + correction_factor});
                break;
            case 'T':
                substr = {line.begin()+3, line.end()};
                iss = std::istringstream{substr};       // string-stream para leitura
                while (iss >> addr) {
                    module->semi_obj_code.push_back(addr);
                }
                break;
        }
    }

    this->Modules.push_back(module);

    return newGlobalDefinitions;
}

void Global_Module::SolveReferences() {
    for (auto & module : this->Modules){
        for (auto & ref : module->uses_table){
            bool isDefinedReference = this->globalDefinitions.find(ref.token) != this->globalDefinitions.end();
            if (isDefinedReference) module->semi_obj_code[ref.addr] += this->globalDefinitions[ref.token];
            else this->NewError("Linker error. Cannto find reference:", ref.token);
        }
    }
}

void Global_Module::NewError(std::string error, const std::string &token) {
    errorsList.push_back(error + token);
}

void Global_Module::SolveRelatives() {
    int cFac = 0;
    for (auto & module : this->Modules) {
        for (int i = 0; i < module->semi_obj_code.size(); ++i) {
            if (module->bit_map[i] == '1') module->semi_obj_code[i] += cFac;
        }
        cFac = module->correction_factor;
    }
}

void Global_Module::link_modules() {
    for (auto & module : this->Modules) {
        auto objCode = module->semi_obj_code;
        this->obj_code.insert(this->obj_code.end(), objCode.begin(), objCode.end()) ;
    }
}
