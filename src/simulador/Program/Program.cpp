//
// Created by Ricardo Santos on 19/07/21.
//

#include <iostream>
#include <fstream>

#include "Program.h"

Program::Program(const std::vector<int> &memory, const std::string &out) : memory(memory), out(out) {}

void Program::run() {
    std::ofstream out_file {this->out, std::ios::trunc};
    if (!out_file) {
        std::cerr << "Error creating exit file " << this->out << std::endl;
        exit(1);
    }

    while (this->exec(memory[PC], out_file));
}

bool Program::exec(int opcode, std::ofstream & ofstream) {
    std::string output;
    switch (opcode) {
        case 1:                             // ADD
            ACC += memory[memory[PC + 1]];    // ACC <- ACC + mem(op)
            break;
        case 2:                             // SUB
            ACC -= memory[memory[PC + 1]];    // ACC <- ACC - mem(op)
            break;
        case 3:                             // MUL
            ACC *= memory[memory[PC + 1]];    // ACC <- ACC * mem(op)
            break;
        case 4:                             // DIV
            ACC /= memory[memory[PC + 1]];    // ACC <- ACC / mem(op)
            break;
        case 5:                             // JMP
            PC = memory[PC + 1];              // PC <- op
            return true;
        case 6:                             // JMPN
            if (ACC < 0) {                  // Se ACC < 0
                PC = memory[PC + 1];          // PC <- op
                return true;
            }
            break;
        case 7:                             // JMPP
            if (ACC > 0) {                  // Se ACC > 0
                PC = memory[PC + 1];          // PC <- op
                return true;
            }
            break;
        case 8:                             // JMPZ
            if (!ACC){                      // Se ACC == 0
                PC = memory[PC + 1];          // PC <- op
                return true;
            }
            break;
        case 9:                             // COPY
            memory[memory[PC + 2]] = memory[memory[PC + 1]];    // mem(op2) <- mem(op1)
            break;
        case 10:                        // LOAD
            ACC = memory[memory[PC + 1]];         // ACC <- mem(op)
            break;
        case 11:                        // STORE
            memory[memory[PC + 1]] = ACC;         // mem(op) <- ACC
            break;
        case 12:                        // INPUT
            std::cin >> memory[memory[PC + 1]];   // mem(op) <- entrada
            break;
        case 13:                         // OUTPUT
            ofstream << memory[memory[PC + 1]] << std::endl; // saída <- mem(op)
            output = "Output: " + std::to_string(memory[memory[PC + 1]]) + "\n"; // saída <- mem(op)
            break;
        case 14:                         // STOP
            return false;

        default:
            break;
    }
    PC += inst_size[opcode];
    std::cout << "PC <- " << PC << "\nACC <- " << ACC << "\n" << output << std::endl;
    return true;
}
