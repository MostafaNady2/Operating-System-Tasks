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

## Command Reference
| Command | Parameters           | Action                                  |
|---------|----------------------|-----------------------------------------|
| RQ      | name size [F\|B\|W] | Request memory allocation               |
| RL      | process_name         | Release allocated memory                |
| C       |                      | Compact memory blocks                   |
| STAT     |                      | Show memory map                         |
| X       |                      | Exit program                            |

**Allocation Example**  
`allocator> RQ Chrome 524288 B`  
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




