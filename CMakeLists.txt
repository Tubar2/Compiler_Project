cmake_minimum_required(VERSION 3.17)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

# MONTADOR
add_executable(Montador
        # FIRST PASS
        src/montador/first_pass/first_pass.cpp
        src/montador/first_pass/first_pass.h

        # SECOND PASS
        src/montador/second_pass/second_pass.cpp
        src/montador/second_pass/second_pass.h

        # STRUCTURE
            # INSTRUCTION
            src/montador/structure/Instruction/Instruction.hpp

            # MODULE
            src/montador/structure/Module/Module.cpp
            src/montador/structure/Module/Module.h
                # AUX
                src/montador/structure/Module/aux/aux.cpp
                src/montador/structure/Module/aux/aux.h
                # ERROR
                src/montador/structure/Module/Error/Error.cpp
                src/montador/structure/Module/Error/Error.h
                # ALIAS
                src/montador/structure/Module/alias/alias.h

            # OBJECT_CODE
            src/montador/structure/Object_Code/Object_Code.h

            # PROGRAM_RAW_FILE
            src/montador/structure/ProgramRawFile/FileLine.hpp
            src/montador/structure/ProgramRawFile/ProgramRawFile.hpp

            # SECTION
            src/montador/structure/Section/Section.hpp

        # UTILS
        src/montador/utils/utils.cpp
        src/montador/utils/utils.hpp

        # DATA
        src/data/data.cpp
        src/data/data.h

        # MONTADOR
        src/montador/montador.cpp
        )

# Ligador
add_executable(Ligador

        src/ligador/structure/Global_Module/Global_Module.cpp
        src/ligador/structure/Global_Module/Global_Module.h

        src/ligador/utils/utils.cpp
        src/ligador/utils/utils.h

        src/ligador/structure/Module/Module.cpp
        src/ligador/structure/Module/Module.h

        src/ligador/structure/Module/Module.cpp
        src/ligador/structure/Module/Module.h

        src/ligador/structure/Module/alias/alias.h

        src/ligador/ligador.cpp
        )

add_executable(Simulador

        src/simulador/simulador.cpp

        src/simulador/Program/Program.cpp
        src/simulador/Program/Program.h)