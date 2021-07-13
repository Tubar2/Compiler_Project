cmake_minimum_required(VERSION 3.17)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Montador
        src/montador/montador.cpp
        src/montador/utils/utils.cpp
        src/montador/Struture/Instruction/Instruction.hpp
        src/montador/Struture/ProgramRawFile/FileLine.hpp src/montador/Struture/ProgramRawFile/ProgramRawFile.hpp src/montador/Struture/Section/Section.hpp)

#add_executable(Ligador src/Ligador/ligador.cpp)