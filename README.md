# Memory Allocator Simulation

A C++ implementation of memory management strategies simulating First Fit, Best Fit, 
and Worst Fit allocation algorithms in a 32-bit system with paged memory.

## Key Features
- **Allocation Strategies**
  - First Fit (`F`): Allocates first available space matching request size
  - Best Fit (`B`): Finds smallest sufficient free block
  - Worst Fit (`W`): Uses largest available free space
- **Memory Operations**
  - Process allocation/deallocation
  - Memory compaction (defragmentation)
  - Real-time status visualization
- **CLI Interface** with familiar OS-style commands

## System Requirements
- C++17 compiler (g++ recommended)
- Build-essential tools
- Unix-like OS or Windows Subsystem for Linux (WSL)

## Quick Start
1. **Compile**  
   `g++ -std=c++17 Memory_Allocator.cpp -o allocator`

2. **Run** (Specify total memory in bytes)  
   `./allocator 1073741824`  
   *(Launches with 1GB simulated memory)*
---
## Commands
- `RQ <process_name> <size> <allocation_strategy>`
    - Request memory allocation
    - Allocation strategies : 
        - `F` : First Fit
        - `B` : Best Fit
        - `W` : Worst Fit
- `RL <process_name>`: Release memory for a specific process
- `C` : Compact memory
- `STAT` : Display memory status
- `X` : Exit the program


**Allocation Example**  
```
allocator> RQ Chrome 524288 B 
allocator> STAT
allocator> RL Chrome
allocator> C
allocator> X
```
Allocates 512KB for "Chrome" using Best Fit strategy

## Technical Details
**Memory Structure**
- 4KB page size (4096 bytes)
- 32-bit address space
- 4-byte memory cell granularity
- Contiguous allocation model

**Algorithm Behavior**
- **First Fit**: Fast allocation, potential external fragmentation
- **Best Fit**: Space-efficient, higher search overhead
- **Worst Fit**: Reduces small fragments, best for large allocations
---
#### Implementation Highlights

- Dynamic memory tracking using C++ STL containers
- Support for multiple concurrent processes
- Flexible allocation strategy selection
- Efficient memory compaction mechanism
---



