# RISC - V CPU emulation 
`+-------------------------------------------------+`  
`|                                                 |`  
`|  RRRR   IIIII   SSSS   CCCC     V V     V V     |`  
`|  R   R    I    S       C        V V   V V       |`  
`|  RRRR     I     SSSS   C         V V V V        |`  
`|  R  R     I         S  C          V V V         |`  
`|  R   R  IIIII   SSSS   CCCC        V V          |`  
`|                                                 |`  
`|            C P U   E M U L A T O R              |`  
`+-------------------------------------------------+`  

**The main aim of this project is to learn the architectural details and implementation of RISC-V CPU. To program the emulator, I have used _C/C++_ language. To build the project I am using _CMake_.**

## RISC-V CPU Introduction
**RISC-V is a modern, open-source instruction set architecture (ISA) that serves as a free and public blueprint for designing computer processors. Unlike proprietary designs, RISC-V can be used and modified by anyone without licensing fees, sparking a wave of innovation. As a result, it is now being used to build the core of a huge range of electronics, including efficient chips for smartphones and laptops, custom processors for data centers and AI, and reliable controllers for automotive systems and industrial machines.**

## Motivation
**This project is a lightweight software emulator for a 32-bit CPU based on the RISC-V Instruction Set Architecture (ISA). It is designed to correctly execute programs compiled for the base integer instruction set (RV32I) by simulating the essential hardware components, including the program counter, general-purpose registers, and a simple memory model. The primary goal is to provide a clear and functional example of how a modern RISC processor operates at the instruction level.**

## References

* https://www.cs.cornell.edu/courses/cs3410/2019sp/schedule/slides/06-cpu-notes-bw.pdf
* https://fraserinnovations.com/risc-v/risc-v-instruction-set-explanation/
