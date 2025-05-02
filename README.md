
# Memory Allocator and Disk Scheduler Simulation

A C++ implementation of memory management strategies and disk scheduling algorithms. The project includes a Memory Allocator simulating First Fit, Best Fit, and Worst Fit allocation algorithms, and a Disk Scheduler implementing FCFS, SCAN, and CSCAN disk scheduling algorithms in a 32-bit system with paged memory.

## Key Features

### Memory Allocator
- **Allocation Strategies**
  - First Fit (`F`): Allocates first available space matching request size
  - Best Fit (`B`): Finds smallest sufficient free block
  - Worst Fit (`W`): Uses largest available free space
- **Memory Operations**
  - Process allocation/deallocation
  - Memory compaction (defragmentation)
  - Real-time status visualization
- **CLI Interface** with familiar OS-style commands

### Disk Scheduler
- **Scheduling Algorithms**
  - FCFS (First-Come-First-Serve): Processes requests in order of arrival
  - SCAN: Moves head in one direction, servicing requests, then reverses
  - CSCAN: Circular SCAN, services requests in one direction, then jumps to start
- **Performance Metrics**
  - Total head movement in cylinders
  - Seek time calculation (assuming 0.1 ms per track)
  - Request order visualization

## System Requirements
- C++17 compiler (g++ recommended)
- Build-essential tools
- Unix-like OS or Windows Subsystem for Linux (WSL)

## Quick Start

### Memory Allocator
1. **Compile**  
   ```bash
   g++ -std=c++17 Memory_Allocator.cpp -o allocator
   ```

2. **Run** (Specify total memory in bytes)  
   ```bash
   ./allocator 1073741824
   ```  
   *(Launches with 1GB simulated memory)*

### Disk Scheduler
1. **Compile**  
   ```bash
   g++ -std=c++17 Disk_Scheduler.cpp -o scheduler
   ```

2. **Run**  
   ```bash
   ./scheduler
   ```  
   *(Prompts for number of tracks, queue size, initial head position, and requests)*

## Commands (Memory Allocator)
- `RQ <process_name> <size> <allocation_strategy>`
  - Request memory allocation
  - Allocation strategies: 
    - `F`: First Fit
    - `B`: Best Fit
    - `W`: Worst Fit
- `RL <process_name>`: Release memory for a specific process
- `C`: Compact memory
- `STAT`: Display memory status
- `X`: Exit the program

**Allocation Example**  
```bash
allocator> RQ Chrome 524288 B 
allocator> STAT
allocator> RL Chrome
allocator> C
allocator> X
```
Allocates 512KB for "Chrome" using Best Fit strategy

## Usage (Disk Scheduler)
- Input the number of tracks, queue size, and initial head position
- Enter the track requests
- Outputs results for FCFS, SCAN, and CSCAN algorithms, including:
  - Total head movement
  - Seek time (0.1 ms per track)
  - Order of serviced requests

**Example Run**  
```bash
Enter the number of tracks: 200
Enter the queue size: 8
Enter the initial head: 50
Enter the requests: 82 170 43 140 24 16 190 120
```

## Technical Details

### Memory Allocator
- **Memory Structure**
  - 4KB page size (4096 bytes)
  - 32-bit address space
  - 4-byte memory cell granularity
  - Contiguous allocation model
- **Algorithm Behavior**
  - **First Fit**: Fast allocation, potential external fragmentation
  - **Best Fit**: Space-efficient, higher search overhead
  - **Worst Fit**: Reduces small fragments, best for large allocations

### Disk Scheduler
- **Disk Structure**
  - Configurable number of tracks
  - Integer-based track requests
  - Head movement measured in cylinders
- **Algorithm Behavior**
  - **FCFS**: Simple, may cause excessive head movement
  - **SCAN**: Efficient for bidirectional access, reduces starvation
  - **CSCAN**: Optimized for circular access, minimizes head movement

## Implementation Highlights
- Dynamic memory tracking using C++ STL containers (Memory Allocator)
- Support for multiple concurrent processes (Memory Allocator)
- Flexible allocation strategy selection (Memory Allocator)
- Efficient memory compaction mechanism (Memory Allocator)
- Accurate head movement and seek time calculations (Disk Scheduler)
- Sorted request handling for SCAN and CSCAN (Disk Scheduler)
- Clear visualization of request order (Disk Scheduler)
