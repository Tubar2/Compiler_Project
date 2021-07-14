//
// Created by Ricardo Santos on 13/07/21.
//

#ifndef COMPILER_MODULE_H
#define COMPILER_MODULE_H


#include <string>
#include <vector>
#include <map>
#include "../Section/Section.hpp"
#include "../Instruction/Instruction.hpp"

typedef struct Symbol_Use_Case {
    std::string label;
    int addr;
} Symbol_Use_Case;

// Estrutura auxilar para identificar se o símbolo é externo
typedef struct Value {
    int addr;
    bool isExtern;
} Value;

// Error structure <name, type, occurrence line>
typedef struct Error {
    std::string error;
    std::string error_type;
    int line;
    // Overloading o opeardo '<' para poder organizar a lista de erros por linha
    bool operator< (const Error &err) const {return line < err.line ;}
} Error;

typedef struct Header {
    std::string name;
} Header;

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
    void processHeader(Section & _header);
    void processHeaderLabel(Instruction & instruction);
    void processHeaderOperation(Instruction & instruction);

    /* DATA METHODS */
    void processData(Section & data, int posCounter);
    int processDataVariable(Instruction & instruction, int posCounter);

    /* TEXT METHODS */
    int processText(Section & text);
    void processTextOperation(Instruction & instruction, int * posCounter);


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
