//
// Created by Ricardo Santos
//

#ifndef COMPILER_MODULE_H
#define COMPILER_MODULE_H


#include <string>
#include <vector>
#include <map>

#include "alias/alias.h"
#include "Error/Error.h"
#include "../Section/Section.hpp"
#include "../Instruction/Instruction.hpp"
#include "../Object_Code/Object_Code.h"


class Module {
public:
    std::string filename;
    Header header;

    /* TABLES */
    // Use case vector
    std::vector<Symbol_Use_Case> usesTable {};

    // Error's list
    std::vector<Error> errorsList{};

    // Definitions map
    std::map<std::string, int> definitionsTable {};

    // Symbols map
    // Label = String
    // Value = {Int, bool}
    std::map<std::string, Value> symbolsTable{};

    /* Methods */

    /* CONSTRUCTOR */
    explicit Module(std::string filename);

    /* HEADER METHODS */
    Instruction_Set header_code;
    void processHeader(Section & _header);
    void defineHeaderLabels(Instruction & instruction);
    void defineHeaderOperations(Instruction & instruction);


    /* DATA METHODS */
    Instruction_Set data_code;
    void processData(Section & data, int posCounter);
    int defineDataVariables(Instruction & instruction, int posCounter);
    Object_Code processDataVariables(Instruction & instruction, int posCounter);


    /* TEXT METHODS */
    Instruction_Set text_code;
    int processText(Section & text);
    void defineTextOperations(Instruction & instruction, int * posCounter);
    Object_Code processTextVariables(Instruction & instruction, int posCounter);

    /* ERROR METHODS */
    void addError(const std::string & error, const std::string & error_type, int line);

    // Auxiliary Methods
    inline void insertLabelIntoSymbols(const Label& label, int addr, bool isExtern){
        symbolsTable.insert({label, {addr, isExtern}});
    }
    inline void defineLabel(const Label& label, int addr){
        definitionsTable.insert({label, addr});
    }
    inline bool labelIsExtern(const Label& label){
        return symbolsTable[label].isExtern;
    }
};


#endif //COMPILER_MODULE_H
