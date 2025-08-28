#include "../header_files/INSTRUNCTION.h"

#include <iostream>

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
    return (0x1F & (addr>>7));
}

// func3 take 3 bits from range 12-14
uint64_t func3(uint32_t addr){
    return (0x7 & (addr>>12));
}

// rs1 takes 5 bits from rnage 15- 19
uint64_t rs1(uint32_t addr){
    return (0x1F & (addr>>15));
}

// rs2 takes 5 bits from range 20 - 24
uint64_t rs2(uint32_t addr){
    return (0x1F & (addr>>20));
}

// func7 takes 7 bits from range 25-31
uint64_t func7(uint32_t addr){
    return (0x7F & (addr>>25));
}

// returns the last 22 bits of the 32 bit wide I-type insstruction

// immediate_i type are signed mode, so we have to maintian the 
// sign bit. If negative number is present we have to ensure the MSB is 1 
int64_t imm_i(uint32_t addr){
    int64_t temp = (addr>>20);
    int64_t shift = 64 - 12;
    temp = (temp << shift) >> shift;
    return temp;
}

// immedetea_s type is also a sigend immediate mode
int64_t imm_s(uint32_t addr) {
   int64_t temp = (addr >> 7) & 0x1F;
   temp = ((((addr >> 25) & 0x7F) << 5) | temp);

   int64_t shift = 64 - 12;
   temp = (temp << shift) >> shift;
   return temp;
}