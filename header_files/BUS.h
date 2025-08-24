#pragma once

#include <cstdint>

#include "./DRAM.h"

typedef struct {
    DRAM dram;
} BUS;

uint64_t load_from_bus(BUS* bus, uint64_t addr, uint64_t size);
void store_on_bus(BUS* bus, uint64_t addr, uint64_t size, uint64_t data);


