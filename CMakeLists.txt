cmake_minimum_required(VERSION 3.10)

project(risc_v_emu CXX)

include_directories(header_files)
# include_directories(src)

add_executable(risc_v_emu
              main.cpp
              src/BUS.cpp
              src/DRAM.cpp
              src/CPU.cpp
              src/INSTRUCTION.cpp
              )
