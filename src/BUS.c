#include "../header_files/BUS.h"

// Bus load and store function are like abstraction,
// and calls dram load and store functions only
// BUS conects the CPU and DRAM chip


/**
 *                                 ----------------
 *                                 | address space |                                  
 * ----------                      |               |
 * |        |________address--->___|other component|
 * |        |                      |---------------|
 * |    CPU |       BUS            |  RAM -0x800.. |
 * |        |______________________|  |        |   |
 * |        |        data---->     |  |  DRAM  |   |
 * ----------        <----data     |  ----------   |
 *                                 |---------------|
 *                                 |               |
 *                                 |               |
 *                                 ----------------
 * 
 * So this is how communication will take place
 * CPU will use bus to interact with the RAM/ or memory 
 * Only CPU can send the request for address so its one directional
 * Data path is bidirectional - so data can move from RAM to CPU or CPU to RAM
 * 
 * SO BUS is the only way CPU communicates with RAM
 * 
 * and we are simulating the same procedure suing these function calls
 */                             

uint64_t load_from_bus(BUS *bus, uint64_t addr, uint64_t size){
    return load_from_dram(&(bus->dram), addr, size);
}

void store_on_bus(BUS *bus, uint64_t addr, uint64_t size, uint64_t data){
    store_to_dram(&(bus->dram), addr, size, data);
}