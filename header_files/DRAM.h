// DRAM is the physical memory system of the RISC-V cpu here
// So the CPU will read data and fetch from this DRAM onlt

#pragma once

#include <cstdint>

// currently we are using only 1MB of 
// DRAM size, as the project currently aims to 
// emulation of simple instruction only (for now)
#define DRAM_SIZE 1*1024*1024

// the starting address of DRAM is always from the 0x80000000
// so basically this defined the physical address of my DRAM 
// when RISC-V emulation works. SO in POV of RISC-V emulation
// this DRAM base is physical address of DRAM chip
#define DRAM_BASE_ADDRESS 0x80000000

// Now because we dont have actual DRAM chip
// we are making this struct to simulate a real DRAM chip
// using a struct object. So we are using an array to mimic the DRAM

// So if we image it, DRAM will start from physical address as
// DRAM_BASE_ADDRESS and then the DRAM_SIZE will be 1MB only
typedef struct {
    uint8_t memory[DRAM_SIZE]; 
} DRAM;




// functions used by CPU to read from the DRAM
// the value of data can be 64bit variable that is why 
// uint64_t is used as return type .So this function is taking
// pointer of DRAM object, the address of data to be read, and 
// the size of data that needs to be readed
uint64_t load_from_dram(DRAM* dram, uint64_t addr, uint64_t size);


// this function to load the data to the DRAM, takes 3 same arguments
// as the load_from_dram, but this function also takes another argument 
// as the data value that needs to be written
void store_to_dram(DRAM *dram, uint64_t addr, uint64_t size, uint64_t data);





