//
// Created by Ricardo Santos on 13/07/21.
//

#include "Module.h"
#include "aux/aux.h"
#include "../../../data/data.h"

//std::map<std::string, int> Module::definitionsTable {};

/* CONSTRUCTOR */
Module::Module(std::string filename) : filename(std::move(filename)) {}


/* HEADER METHODS */
void Module::processHeader(Section & _header) {
    for (auto & line : _header.lines){
        auto instruction = toInstruction(line);
        // 'begin' or 'extern'
        if (!instruction.label.empty()){
            this->processHeaderLabel(instruction);
        }
        // 'public'
        else if (!instruction.operation.empty()){
            this->processHeaderOperation(instruction);
        }

    }
}

void Module::processHeaderLabel(Instruction & instruction) {
    bool inMap = this->symbolsTable.find(instruction.label) != this->symbolsTable.end();
    if (!inMap) {
        // 'begin'
        if (!instruction.operation.empty()){
            if (instruction.operation == "begin") {
                this->insertLabelIntoSymbols(instruction.label, 0, false);
                this->header.name = instruction.label;
            } else if (instruction.operation == "extern"){
                this->insertLabelIntoSymbols(instruction.label, 0, true);
            } else {
                // TODO: Erro, diretiva inválida
            }
        }
        // TODO; Erro, num operandos inválido
    }
    else {
        //TODO: Erro, label redefinido
    }

}

void Module::processHeaderOperation(Instruction &instruction) {
    bool isInstruction = Header_operation_set.find(instruction.operation) != Header_operation_set.end();
    if (isInstruction){
        if (instruction.operation == "public"){
            if (instruction.operands.size() == 1){
                this->defineLabel(instruction.operands[0], 0);
                bool inSymbolTable = this->symbolsTable.find(instruction.operands[0]) != this->symbolsTable.end();
                if (inSymbolTable && this->labelIsExtern(instruction.operands[0])){
                    // TODO: Erro símbolo externo redefinido como publico
                }
            } else {
                // TODO: Erro quadntidade de operandos
            }
        }
    } else {
        // TODO: Erro Operação não definida
    }
}


/* DATA METHODS */
void Module::processData(Section &data, int posCounter) {
    for (auto & line : data.lines){
        auto instruction = toInstruction(line);
        // Checks for label
        this->processDataVariable(instruction, posCounter);
    }


}

int Module::processDataVariable(Instruction &instruction, int posCounter) {
    if (!instruction.label.empty()){
        if (!instruction.operation.empty()){
            auto directive = Data_operation_set.find(instruction.operation);
            bool isDirective = directive != Data_operation_set.end();
            if (isDirective){
                bool isInSymbols = this->symbolsTable.find(instruction.label) != this->symbolsTable.end();
                if (!isInSymbols){
                    this->insertLabelIntoSymbols(instruction.label, posCounter, false);
                } else {
                    // TODO: Erro

                }
                posCounter += directive->second.size;
            }
        }
    }
    return posCounter;
}


/* TEXT METHODS */
int Module::processText(Section &text) {
    int posCounter = 0;
    for (auto & line : text.lines){
        auto instruction = toInstruction(line);
        // Checks for label
        this->processTextOperation(instruction, &posCounter);
    }
    return posCounter;
}

void Module::processTextOperation(Instruction &instruction, int * posCounter) {
    if (!instruction.label.empty()){
        bool isInSymbols = this->symbolsTable.find(instruction.label) != this->symbolsTable.end();
        if (!isInSymbols){
            this->insertLabelIntoSymbols(instruction.label, *posCounter, false);
        } else {
            // TODO: Erro
        }
    }
    if (!instruction.operation.empty()){
        auto operation = Text_operation_set.find(instruction.operation);
        bool isOperation = operation != Text_operation_set.end();
        if (isOperation){
            *posCounter += operation->second.size;
        }
    }
}
