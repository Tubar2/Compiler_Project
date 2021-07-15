cmake_minimum_required(VERSION 3.17)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Montador
        # FIRST PASS
        src/montador/first_pass/first_pass.cpp
        src/montador/first_pass/first_pass.h

        # INSTRUCTION
        src/montador/structure/Instruction/Instruction.hpp

        # MODULE
            src/montador/structure/Module/aux/aux.cpp
            src/montador/structure/Module/aux/aux.h
        src/montador/structure/Module/Module.cpp
        src/montador/structure/Module/Module.h

        # ProgramRawFile
        src/montador/structure/ProgramRawFile/FileLine.hpp
        src/montador/structure/ProgramRawFile/ProgramRawFile.hpp

        # SECTION
        src/montador/structure/Section/Section.hpp

        # UTILS
        src/montador/utils/utils.cpp
        src/montador/utils/utils.hpp

        # MONTADOR
        src/montador/montador.cpp
        src/data/data.cpp src/data/data.h src/montador/second_pass/second_pass.cpp src/montador/second_pass/second_pass.h src/montador/structure/Object_Code/Object_Code.h src/montador/structure/Module/module_aliases/module_aliases.h src/montador/structure/Module/Error/Error.cpp src/montador/structure/Module/Error/Error.h)

#add_executable(Ligador src/ligador/ligador.cpp)