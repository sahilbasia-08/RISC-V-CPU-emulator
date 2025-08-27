#pragma once
#include "../header_files/BUS.h"

typedef struct {
    uint64_t cpu_reg[32]={0}; // RISC - V CPU has total of 32 registers
                          // 0x0 wil be hardwarired to the 0 value,
                          // rest will be used for storing values
    uint64_t pc;          // Program counter register - to store the address of next instruction
                          // that will be executed , address are 64bit -therefore uint64_t
    
    BUS bus;              // THis bus object is used to connect the CPU to the bus, 
                          // so when an object of the CPU is created, it atuomatically creates
                          // a bus object - if CPU is their, then their will definately be bus
} CPU;


void cpu_init(CPU *cpu);         // this function will initialize the CPU to factory reset
uint32_t cpu_fetch(CPU *cpu);    // THe cpu will read the DRAM to get the instruction. 
                                 // using bus it will fetch the instruction
                                 // base instruction size in risc V is 32 bit size
                                 // but it support variable length instrn size also


uint64_t cpu_execute(CPU *cpu);  // this function will do both works 
                                 // of decode and executin the fetched instruction

void dump_register_content(CPU *cpu);

void cpu_store(CPU *cpu, uint64_t addr, uint64_t size, uint64_t data);
uint64_t cpu_load(CPU *cpu, uint64_t addr, uint64_t size);