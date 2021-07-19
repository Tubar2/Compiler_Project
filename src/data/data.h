//
// Created by Ricardo Santos
//

#ifndef COMPILER_DATA_H
#define COMPILER_DATA_H

#include <string>
#include <map>

typedef std::string Operation_Name;

typedef struct Operation_Properties {
    int operands;
    int size;
    int opcode;
} Operation_Properties;

// Maps 'operation name' to {operands, address}
extern std::map<Operation_Name, Operation_Properties> Header_operation_set;

extern std::map<Operation_Name, Operation_Properties> Data_operation_set;

extern std::map<Operation_Name, Operation_Properties> Text_operation_set;

// Maps an opcode to it's size
extern std::map<int, int> operation_size;

#endif //COMPILER_DATA_H
