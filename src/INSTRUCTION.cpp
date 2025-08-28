#include "../header_files/INSTRUNCTION.h"

// returning the LSB 7 bit, from the instruction at addrress addr in DRAM
// LSB 7 bits contains the opsocde basically
uint64_t opcode(uint32_t addr){
    return (addr & 0x7F);
}

// rd takes 5 bits in 32 bit wide instrunction, 
// and ranges from 7-11 bit range, so to get those 5 bits
// we are using 0x1F<<7 :- basically shifting the 0x0001 1111 to left 7 times 
// to get those 5 bits from 7-11 range in 32 bit 
uint64_t rd(uint32_t addr){
    return (addr & (0x1F<<7));
}

// func3 take 3 bits from range 12-14
uint64_t func3(uint32_t addr){
    return (addr & (0x3<<12));
}

// rs1 takes 5 bits from rnage 15- 19
uint64_t rs1(uint32_t addr){
    return (addr & (0x1F<<15));
}

// rs2 takes 5 bits from range 20 - 24
uint64_t rs2(uint32_t addr){
    return (addr & (0x1F<<20));
}

// func7 takes 7 bits from range 25-31
uint64_t func7(uint32_t addr){
    return (addr & (0x7F<<25));
}

// returns the last 22 bits of the 32 bit wide I-type insstruction
uint64_t imm_i(uint32_t addr){
    return (addr & (0xFFF<<20));
}

uint64_t imm_s(uint32_t addr){
    uint64_t temp =0x0;
    temp |= (addr & (0x1F)<<7);
    temp |= (((addr & 0x7F)<<25)<5);

    return temp;
}