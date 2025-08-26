#include "../header_files/CPU.h"

void cpu_init(CPU *cpu){
    // https://en.wikichip.org/wiki/risc-v/registers refer this for cpu register info

    // I am making a table here only of the registers table, for quick reference
    
/* ===============================================================
   RISC-V General Purpose Registers (x0 - x31)
   ---------------------------------------------------------------
   Num   ABI   Name      Description
   ===============================================================
   x0    zero   -        Hardwired zero
   x1    ra     -        Return address
   x2    sp     -        Stack pointer
   x3    gp     -        Global pointer
   x4    tp     -        Thread pointer
   x5    t0     -        Temporary register 0
   x6    t1     -        Temporary register 1
   x7    t2     -        Temporary register 2
   x8    s0/fp  -        Saved register 0 / Frame pointer
   x9    s1     -        Saved register 1
   x10   a0     -        Function argument 0 / Return value 0
   x11   a1     -        Function argument 1 / Return value 1
   x12   a2     -        Function argument 2
   x13   a3     -        Function argument 3
   x14   a4     -        Function argument 4
   x15   a5     -        Function argument 5
   x16   a6     -        Function argument 6
   x17   a7     -        Function argument 7
   x18   s2     -        Saved register 2
   x19   s3     -        Saved register 3
   x20   s4     -        Saved register 4
   x21   s5     -        Saved register 5
   x22   s6     -        Saved register 6
   x23   s7     -        Saved register 7
   x24   s8     -        Saved register 8
   x25   s9     -        Saved register 9
   x26   s10    -        Saved register 10
   x27   s11    -        Saved register 11
   x28   t3     -        Temporary register 3
   x29   t4     -        Temporary register 4
   x30   t5     -        Temporary register 5
   x31   t6     -        Temporary register 6
*/ 

    cpu->pc = DRAM_BASE_ADDRESS;
    cpu->cpu_reg[0]=0x00;
    cpu->cpu_reg[2]=DRAM_BASE_ADDRESS+DRAM_SIZE; // stack grows upwards or moves bottom to up 
}

uint32_t cpu_fetch(CPU *cpu){
    uint32_t inst = load_from_bus(&(cpu->bus), cpu->pc, 32); // 32 bit is size we are fetching at one 
                                                             // moment from the DRAM.
                                                             // currentyl we are just supporting the 
                                                             // 32 bit instruction size , not wriitng
                                                             // support for 16 bit and and other variabvle size instruction sizes
}

