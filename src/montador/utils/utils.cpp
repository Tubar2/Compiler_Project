//
// Created by Ricardo Santos
//

#include <iostream>
#include <fstream>
#include <sstream>


#include "utils.hpp"


std::string removeExtension(const char * s){
    std::string str(s);
    str = str.substr(0, str.find_last_of('.'));
    return str;
}

ProgramRawFile * readRawIntoModule(const std::string& filename) {
    std::cout << "Reading: " << filename << std::endl;
    // Opening file for reading
    std::ifstream file {filename};
    if (!file) {
        // Arquivo não encotrado
        std::cerr << "Error opening file" << std::endl;
        std::exit(1);
    }

    // Auxiliary Variables
    std::string line;   // 'line' represents a single line of the program
    std::string token;   // 'word' will hold each token in a given line
    int lineCounter{1}; // 'line' represents the cursor's current position in a document
    Section header{}, data{}, text{};   // Parts of the file having header information,
                                        // data (.data) or text (.text) instructions
    // Header always comes first
    int status = 1;
    bool insertion;
    bool  has_end = false;
    while (std::getline(file, line)) {
        insertion = true;
        FileLine fileLine {};
        std::cout << line << std::endl;
        std::istringstream iss{line};   // string-stream for reading from line
        // Skipping white spaces and reading only tokens
        while (iss >> token) {
            // Check for comments
            if (token[0] == ';') { break; }
            // Transform each token to loswer case
            std::transform(token.begin(), token.end(), token.begin(), ::tolower);
            token.erase(std::remove(token.begin(), token.end(), ','), token.end());
            // Check for section
            if (token == ".data") {status = 2; insertion= false; break;}
            if (token == ".text") {status = 3; insertion= false; break;}
            // Check for ".end"
            if (token == ".end") {has_end = true; insertion= false; break;}

            fileLine.tokens.push_back(token);
        }
        fileLine.line_number = lineCounter++;
        if (!fileLine.tokens.empty() && insertion){
            switch (status) {
                case 1: // Insert in header
                    header.lines.push_back(fileLine);
                    break;
                case 2: // Insert in data
                    data.lines.push_back(fileLine);
                    break;
                case 3: // Insert in text
                    text.lines.push_back(fileLine);
                    break;
                default:
                    break;
            }
        }
    }

    auto * rawFile = new ProgramRawFile;
    rawFile->name = filename;
    rawFile->header = header;
    rawFile->data = data;
    rawFile->text = text;
    rawFile->has_end = has_end;

    file.close();
    return rawFile;
}

bool checkForErrors(Module & module){
    if (!module.errorsList.empty()){
        std::sort(module.errorsList.begin(), module.errorsList.end());
        for (const auto & error : module.errorsList){
            std::cout << std::left;
            std::cout << std::setfill(' ') << std::setw(21) << "Erro "+ error.error_type +": ";
            std::cout << std::setfill(' ') << std::setw(13)<< "Linha: "+std::to_string(error.line) + " ";
            std::cout << error.error << std::endl;
        }
        return true;
    }
    return false;
}

void writeToObjFile(std::vector<int> & obj_code, Module & module) {
    std::ofstream out_file {"/Users/ricardosantos/Developer/C++/Compiler/resource/object/"+module.header.name+".obj", std::ios::trunc};
    if (!out_file){
        std::cerr << "Error creating exit file " << module.header.name << std::endl;
        exit(1);
    } else {
        out_file << "H: " << module.header.name << "\n";
        out_file << "H: " << obj_code.size() << "\n";
        out_file << "R: " <<  module.header.bit_map << "\n";
        for (auto & use_case : module.usesTable){
            out_file << "U: " << use_case.label << " " << use_case.addr << "\n";
        }
        for (auto & definedSymbol : module.definitionsTable){
            out_file << "D: " << definedSymbol.first << " " << definedSymbol.second << "\n";
        }
        out_file << "T: ";
        for (auto code : obj_code){
            out_file << code << " ";
        }
    }
    out_file.close();
}