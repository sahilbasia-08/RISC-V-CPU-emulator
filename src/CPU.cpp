#include "../header_files/CPU.h"

void cpu_init(CPU *cpu){
    // https://en.wikichip.org/wiki/risc-v/registers refer this for cpu register info
    cpu->pc = DRAM_BASE_ADDRESS;
    cpu->cpu_reg[0]=0x00;
    cpu->cpu_reg[2]=DRAM_BASE_ADDRESS+DRAM_SIZE; // stack grows upwards or moves bottom to up 
}