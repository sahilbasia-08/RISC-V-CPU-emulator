#pragma once

#include <cstdint>


uint64_t opcode(uint32_t addr);
uint64_t rd(uint32_t addr);
uint64_t func3(uint32_t addr);
uint64_t rs1(uint32_t addr);
uint64_t rs2(uint32_t addr);
uint64_t func7(uint32_t addr);
int64_t imm_s(uint32_t addr); // basically this imm behaves differently for different 
                                             // instructions, so therefore we are adding a shift arugment
                                             // which will be passed based on the instruction
int64_t imm_b(uint32_t addr);
uint64_t imm_u(uint32_t addr);
int64_t imm_j(uint32_t addr);
int64_t imm_i(uint32_t addr);