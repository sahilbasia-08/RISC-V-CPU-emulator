#include "../header_files/INSTRUNCTION.h"

#include <iostream>

// Currently we programming for the 32 bit wide instruction lenght
// and thereby emulating for RV32 architecture

// returning the LSB 7 bit, from the instruction at addrress addr in DRAM
// LSB 7 bits contains the opcode basically
uint64_t opcode(uint32_t instrn){
    return (instrn & 0x7F);
}

// rd takes 5 bits in 32 bit wide instrunction, 
// and ranges from 7-11 bit range, so to get those 5 bits
// we are using 0x1F<<7 :- basically shifting the 0x0001 1111 to left 7 times 
// to get those 5 bits from 7-11 range in 32 bit 
uint64_t rd(uint32_t instrn){
    return (0x1F & (instrn>>7));
}

// func3 take 3 bits from range 12-14
uint64_t func3(uint32_t instrn){
    return (0x7 & (instrn>>12));
}

// rs1 takes 5 bits from rnage 15- 19
uint64_t rs1(uint32_t instrn){
    return (0x1F & (instrn>>15));
}

// rs2 takes 5 bits from range 20 - 24
uint64_t rs2(uint32_t instrn){
    return (0x1F & (instrn>>20));
}

// func7 takes 7 bits from range 25-31
uint64_t func7(uint32_t instrn){
    return (0x7F & (instrn>>25));
}

// returns the last 22 bits of the 32 bit wide I-type insstruction

// immediate_i type are signed mode, so we have to maintian the 
// sign bit. If negative number is present we have to ensure the MSB is 1 
int64_t imm_i(uint32_t instrn){
    int64_t temp = (instrn>>20);
    int64_t shift = 64 - 12;
    temp = (temp << shift) >> shift;
    return temp;
}

// immedetea_s type is also a sigend immediate mode, so we are keeping 
// using a sign extension mechanism to maintain the sign bit
int64_t imm_s(uint32_t instrn) {
   int64_t temp = (instrn >> 7) & 0x1F;
   temp = ((((instrn >> 25) & 0x7F) << 5) | temp);

   int64_t shift = 64 - 12;
   temp = (temp << shift) >> shift;
   return temp;
}
// for immediate in J type, we have this 
// imm[20]   = instrn[31]
// imm[10:1] = instrn[30:21]
// imm[11]   = instrn[20]
// imm[19:12]= instrn[19:12]

int64_t imm_j(uint32_t instrn){
    int64_t temp = 0;
    temp |= ((instrn >> 21) & 0x3FF ) <<1;// this is for imm[10:1]
    temp |= ((instrn >> 20) & 0x1 ) << 11; // this is for imm[11]
    temp |= ((instrn >> 12) & 0xFF ) << 12; // this is for imm[19:12]
    temp |= ((instrn >> 31) & 0x1) << 20; // this is for imm[20]

    // performing sign extension, as this immediates can be sign value also
    int64_t shift = 64 - 21;
    temp = (temp << shift) >> shift;

    return temp;
}

// for immediate in U type 
uint64_t imm_u(uint32_t instrn){
    return (instrn & 0xFFFFF999);
}

// this immediate is for break type instructions
int64_t imm_b(uint32_t instrn){
    int64_t temp = 0;
    temp |= ((instrn >> 8) & 0xF) << 1; // imm[12] from bit 31
    temp |= ((instrn >> 7) & 0x1 ) << 11; // imm[11] from bit 7
    temp |= ((instrn >> 25) & 0x3F) <<5; // imm[10:5] from bits 30..25
    temp |= ((instrn >> 31) & 0x1) << 12; // imm[12] from bit 31
    // performing the sign extension 
    int64_t shift = 64 - 11;
    temp = (temp << shift) >> shift;
    return temp;
}