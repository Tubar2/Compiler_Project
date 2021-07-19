//
// Created by Ricardo Santos on 19/07/21.
//

#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include <vector>
#include <string>
#include <map>

class Program {
private:
    int ACC {0};
    int PC {0};
    std::vector<int> memory;
    std::string out;

    std::map<int, int> inst_size{
            {1, 2},
            {2, 2},
            {3, 2},
            {4, 2},
            {5, 2},
            {6, 2},
            {7, 2},
            {8, 2},
            {9, 3},
            {10, 2},
            {11, 2},
            {12, 2},
            {13, 2},
            {14, 1},
    };

public:

    /* CONSTRUCTOR */
    Program(const std::vector<int> &memory, const std::string &out);

    void run();

    bool exec(int opcode, std::ofstream & ofstream);
};


#endif //COMPILER_PROGRAM_H
