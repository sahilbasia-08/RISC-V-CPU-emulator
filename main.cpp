#include "./header_files/BUS.h"
#include "./header_files/DRAM.h"
#include "./header_files/CPU.h"

#include <iostream>

int main(){
    std::cout<<"RISC V emulation working"<<std::endl;
    // BUS bus;
    // store_on_bus(&bus, 0x8, 32, 1);
    CPU cpu;
    std::cout<<" -> Initializing the CPU"<<std::endl;
    cpu_init(&cpu);
    std::cout<<"\n";
    std::cout<<" -> Dumping register content of the current state of the CPU"<<std::endl;
    dump_register_content(&cpu);
    std::cout<<"\n";
    std::cout<<" -> Testing cpu load and store to some x address"<<std::endl;
    std::cout<<"Storing value 10919191919 for testing at address 0x80000000"<<std::endl;
    cpu_store(&cpu, 2147483648, 64, (uint64_t)10919191919);
    std::cout<<"value loaded is "<<cpu_load(&cpu, 2147483648, 64)<<std::endl;
    return 0;
}