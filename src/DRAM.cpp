#include <iostream>

#include "../header_files/DRAM.h"

uint64_t load_from_dram(DRAM* dram, uint64_t addr, uint64_t size){
    // Reading the data value fdrom the dram
    return (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS];
}

void store_to_dram(DRAM *dram, uint64_t addr, uint64_t size, uint64_t data){
    dram->memory[addr - DRAM_BASE_ADDRESS] = (uint8_t)data;
}