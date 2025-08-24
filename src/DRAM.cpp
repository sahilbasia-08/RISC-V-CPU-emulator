#include <iostream>

#include "../header_files/DRAM.h"

/*
    RISC - V uses little endian system. So LSB is stored
    at the lowed address

*/

uint64_t load_from_dram(DRAM* dram, uint64_t addr, uint64_t size){
    // Reading the data value fdrom the dram
    // based on the size value, we will read the data accordingly.
    // RAM is 8 bits, so at particular moment we can read 8 bits in one go from the ram 

    // addr - DRAM_BASE_ADDRESS is done to ensure that we access ram array in 0 base indexing 
    // becuase the data structyuew we use for the DRAM memory is array 

    
    if(size == 8){
        return (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS];
    }

    else if(size == 16){
        // we will perform 2 read operating to read the whole 16 bits
        // So we will be requiring 8bit shift to read 
        // the whole 16 bits range

        // according to little endian memory system
        // (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS] is readign the lower bits (0-7)
        // (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS + 1] will read the (8 - 15)

        // basically ||   RAM CONTENT         || 
        // ||          0-7 bits               || +0
        // ||          8-15 bits              || +1

        // so to make proper 16 bits of value, we are shifting those 8-15 bit to right so to make them
        // 15 14 .. 8 7 6 .. 2 1

        // now this will be now a proper 16 bit size data value
        return (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS] | 
               (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS + 1] <<8;
    }

    else if(size == 32){
        // Similalry for this also, we will be needing 4 access to read 


        // Similar to 16 bit value
        // we are now reading 4 consecutive 8 bit blocks from the DRAM memory area
        // and also shifting them to required byte position

        // ||            0-7                || +0
        // ||            8-15               || +1
        // ||            16-23              || +2 
        // ||            24-31              || +3
        return (uint16_t)dram->memory[addr - DRAM_BASE_ADDRESS] | 
        (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +1] <<8 |
        (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +2] <<16|
        (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +3] <<24;
    }
    else if(size == 64){
        // ||            0-7                || +0
        // ||            8-15               || +1
        // ||            16-23              || +2 
        // ||            24-31              || +3
        // ||            32-39              || +4
        // ||            40-47              || +5
        // ||            48-55              || +6
        // ||            56-63              || +7
        return (uint16_t)dram->memory[addr - DRAM_BASE_ADDRESS] 
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +1] <<8 
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +2] <<16
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +3] <<24
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +4] <<32
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +5] <<40
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +6] <<48
        | (uint64_t)dram->memory[addr - DRAM_BASE_ADDRESS +7] <<56;
    }
    else{
        std::cerr<<"Cannont read for a unkown size value, returning \n";
        exit(-1);
    }
}

// Similar to load_from_dram, the memory address will
// be calculated in 0 base indexing form, becuase memory is array data structure

void store_to_dram(DRAM *dram, uint64_t addr, uint64_t size, uint64_t data){

    // since data can be 64 bit, therefore we are using 0xff - 1111 1111 binary
    // to capture the first 8 bits from the right

    if(size == 8){
        dram->memory[addr - DRAM_BASE_ADDRESS] = (uint8_t)(data & 0xff);
    }
    else if(size == 16){
        // 0x1234 is the number
        // then data & 0xff = 34 only, so last 2 captured and now we will store them 
        // according to little endian system, first LSB will be stored on lower memory address

        // so ram | 0 | = 34
        //    ram | 1 | = 12
        
        dram->memory[addr - DRAM_BASE_ADDRESS] = (uint8_t)(data & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+1] = (uint8_t)((data>>8) & 0xff);

    }
    else if(size == 32){
        // Similarly as sie 16, we will do 3 times right shift to easily place the 
        // the data on the desired address in sDRAM

        // 0x12345678

        // ram | 0 | = 78
        // ram | 1 | = 56
        // ram | 2 | = 34
        // ram | 3 | = 12

        dram->memory[addr - DRAM_BASE_ADDRESS] = (uint8_t)(data & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+1] = (uint8_t)((data>>8) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+2] = (uint8_t)((data>>16) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+3] = (uint8_t)((data>>24) & 0xff);
    }
    else if(size == 64){
        // 0x123456789ABCDEFH

        // ram | 0 | = FH
        // ram | 1 | = DE
        // ram | 2 | = BC
        // ram | 3 | = 9A
        // ram | 4 | = 78
        // ram | 5 | = 56
        // ram | 6 | = 34
        // ram | 7 | = 12

        dram->memory[addr - DRAM_BASE_ADDRESS] = (uint8_t)(data & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+1] = (uint8_t)((data>>8) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+2] = (uint8_t)((data>>16) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+3] = (uint8_t)((data>>24) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+4] = (uint8_t)((data>>32) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+5] = (uint8_t)((data>>40) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+6] = (uint8_t)((data>>48) & 0xff);
        dram->memory[addr - DRAM_BASE_ADDRESS+7 ] = (uint8_t)((data>>56) & 0xff);
    }
    else{
        std::cerr<<"Unkown size passed. Pass correct size values from 8, 16, 32, 64 \n EXITING!! \n";
        exit(-1);
    }

}