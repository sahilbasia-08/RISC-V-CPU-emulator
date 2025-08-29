#include "./header_files/BUS.h"
#include "./header_files/DRAM.h"
#include "./header_files/CPU.h"
#include "./header_files/INSTRUNCTION.h"

#include <iostream>

static void test_decode_word(CPU* cpu, uint32_t addr, const char* label) {
    uint32_t inst = (uint32_t)cpu_load(cpu, addr, 32);  // read back 32-bit word
    std::cout << label << " @0x" << std::hex << addr << " inst=0x" << inst << std::dec << "\n";
    std::cout << "  opcode=" << opcode(inst)
              << " rd="     << rd(inst)
              << " funct3=" << func3(inst)
              << " rs1="    << rs1(inst)
              << " rs2="    << rs2(inst)
              << " funct7=" << func7(inst) << "\n";

    // Try each immediate; print what makes sense for that format
    std::cout << "  imm_i=" << imm_i(inst)
              << "  imm_s=" << imm_s(inst)
              << "  imm_j=" << imm_j(inst) << "\n\n";
}


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
    // std::cout<<" -> Testing cpu load and store to some x address"<<std::endl;
    // std::cout<<"Storing value 10919191919 for testing at address 0x80000000"<<std::endl;
    // cpu_store(&cpu, 2147483648, 64, (uint64_t)10919191919);
    // std::cout<<"value loaded is "<<cpu_load(&cpu, 2147483648, 64)<<std::endl;

    // imm_s(2147483648);


    uint32_t inst_addi = 0xFFF00093; // ADDI x1,x0,-1
    uint32_t inst_sw   = 0xFE552823; // SW x5,-16(x10)
    uint32_t inst_jalP = 0x010000EF; // JAL x1,+16
    uint32_t inst_jalN = 0xFFDFF0EF; // JAL x1,-4

    cpu_store(&cpu, DRAM_BASE_ADDRESS + 0x00, 32, inst_addi);
    cpu_store(&cpu, DRAM_BASE_ADDRESS + 0x04, 32, inst_sw);
    cpu_store(&cpu, DRAM_BASE_ADDRESS + 0x08, 32, inst_jalP);
    cpu_store(&cpu, DRAM_BASE_ADDRESS + 0x0C, 32, inst_jalN);
    test_decode_word(&cpu, DRAM_BASE_ADDRESS + 0x00, "ADDI x1,x0,-1");
    test_decode_word(&cpu, DRAM_BASE_ADDRESS + 0x04, "SW   x5,-16(x10)");
    test_decode_word(&cpu, DRAM_BASE_ADDRESS + 0x08, "JAL  x1,+16");
    test_decode_word(&cpu, DRAM_BASE_ADDRESS + 0x0C, "JAL  x1,-4");
    return 0;
}