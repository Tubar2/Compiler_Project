//
// Created by Ricardo Santos on 14/07/21.
//

#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H


#include <string>

class Error {
public:
    std::string error;
    std::string error_type;
    int line;

    /* CONSTRUCTOR */
public:
    Error(const std::string &error, const std::string &errorType, int line);

    // Overloading o opeardo '<' para poder organizar a lista de erros por linha
    bool operator< (const Error &err) const {return line < err.line ;}

//    friend std::ostream& operator<< (std::ostream& stream, const Error & error) {
//        return std::left <<
//        std::cout << std::setfill(' ') << std::setw(21) << "Erro "+ error.error_type +": ";
//        std::cout << std::setfill(' ') << std::setw(13)<< "Linha: "+std::to_string(error.line) + " ";
//        std::cout << error.error << std::endl;
//    }

};


#endif //COMPILER_ERROR_H
