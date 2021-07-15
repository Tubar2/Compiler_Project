//
// Created by Ricardo Santos on 13/07/21.
//

#include "Module.h"
#include "aux/aux.h"
#include "../../../data/data.h"
#include "../Object_Code/Object_Code.h"

//std::map<std::string, int> Module::definitionsTable {};

/* CONSTRUCTOR */
Module::Module(std::string filename) : filename(std::move(filename)) {}


/* HEADER METHODS */
void Module::processHeader(Section & _header) {
    for (auto & line : _header.lines){
        auto instruction = toInstruction(line);
        this->header_code.push_back(instruction);
        // 'begin' or 'extern'
        if (!instruction.label.empty()){
            this->defineHeaderLabels(instruction);
        }
        // 'public'
        else if (!instruction.operation.empty()){
            this->defineHeaderOperations(instruction);
        }

    }
}

void Module::defineHeaderLabels(Instruction & instruction) {
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

void Module::defineHeaderOperations(Instruction &instruction) {
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
        this->data_code.push_back(instruction);
        // Checks for label
        posCounter = this->defineDataVariables(instruction, posCounter);
    }


}

int Module::defineDataVariables(Instruction &instruction, int posCounter) {
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

Object_Code Module::processDataVariables(Instruction &instruction, int posCounter) {
    Object_Code obj_file {};
    bool isInstruction = Data_operation_set.find(instruction.operation) != Text_operation_set.end();
    if (!isInstruction){
        // TODO: Erro
        this->addError("Undefined instruction: " + instruction.operation, "", instruction.instructionLine);
    } else {
        if (instruction.operation == "space") {
            this->header.bit_map += "0";
            obj_file.push_back(0);
        } else if (instruction.operation == "const"){
            this->header.bit_map += "0";
            obj_file.push_back(std::stoi(instruction.operands[0]));
        }
    }
    return obj_file;
}


/* TEXT METHODS */
int Module::processText(Section &text) {
    int posCounter = 0;
    for (auto & line : text.lines){
        auto instruction = toInstruction(line);
        this->text_code.push_back(instruction);
        // Checks for label
        this->defineTextOperations(instruction, &posCounter);
    }
    return posCounter;
}

void Module::defineTextOperations(Instruction &instruction, int * posCounter) {
    if (!instruction.label.empty()){
        bool isInSymbols = this->symbolsTable.find(instruction.label) != this->symbolsTable.end();
        if (!isInSymbols){
            this->insertLabelIntoSymbols(instruction.label, *posCounter, false);
        } else {
            // TODO: Erro, label redefinido
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

Object_Code Module::processTextVariables(Instruction &instruction, int posCounter) {
    Object_Code obj_file {};
    if (!instruction.operation.empty()){
        bool isInstruction = Text_operation_set.find(instruction.operation) != Text_operation_set.end();
        if (!isInstruction && instruction.isEmpty()) {
            // TODO: Erro
            this->addError("Undefined instruction: " + instruction.operation, "", instruction.instructionLine);
        } else {
            obj_file.push_back(Text_operation_set[instruction.operation].opcode);
            this->header.bit_map += "0";
            for (auto &operand : instruction.operands) {
                if (this->symbolsTable[operand].isExtern){
                    this->usesTable.push_back({
                        operand,
                        static_cast<int>(posCounter + obj_file.size())
                    });
                    this->header.bit_map += "0";
                } else {
                    this->header.bit_map += "1";
                }
                obj_file.push_back(this->symbolsTable[operand].addr);
            }
        }
    }
    return obj_file;
}


/* ERROR METHODS */
void Module::addError(const std::string & error, const std::string & error_type, int line) {
    this->errorsList.emplace_back(error, error_type, line);
}
