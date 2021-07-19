//
// Created by Ricardo Santos
//

#ifndef COMPILER_OBJECT_CODE_H
#define COMPILER_OBJECT_CODE_H

#include <vector>

// Programa como código objeto
// É um vector<int> apenas com os números após 'end xx.' no exemplo abaixo:
// end 00. 12  0
// end 02. 10  11
// end 04. 14
// end 05. 5
// => [12, 0, 10, 11, 14, 5]
typedef std::vector<int> Object_Code;

#endif //COMPILER_OBJECT_CODE_H
