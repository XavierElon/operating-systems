# Module 2: Memory Management

## Learning Objectives

- Understand virtual memory and memory mapping
- Learn heap management with malloc/free
- Understand the difference between stack and heap
- Learn to use mmap() for memory mapping
- Understand memory layout in a process

## Files

- `mmap_example.c` - Basic memory mapping with anonymous memory
- `mmapped_file.c` - Memory-mapped file I/O
- `heap_basics.c` - malloc, calloc, realloc, and free
- `virtual_memory.c` - Virtual memory concepts and address space layout

## Build & Run

make # Build all programs
make run-mmap # Run mmap_example
make run-heap # Run heap_basics
make run-virtual # Run virtual_memory
make run-mmapped-file # Run mmapped_file
make clean # Remove compiled files## Key Concepts

### Virtual Memory

- Each process has its own virtual address space
- OS maps virtual addresses to physical addresses
- Pages are the unit of virtual memory (typically 4KB)

### Memory Layout

- **Text segment**: Code (instructions)
- **Data segment**: Global and static variables
- **Heap**: Dynamically allocated memory (grows up)
- **Stack**: Local variables and function calls (grows down)

### System Calls

- `mmap()`: Map memory or files into address space
- `munmap()`: Unmap memory
- `brk()`/`sbrk()`: Adjust heap size (used by malloc internally)
- `malloc()`/`free()`: Heap allocation (library functions, not system calls)

## Exercises

1. Modify `heap_basics.c` to detect memory leaks (use valgrind on Linux)
2. Change `mmapped_file.c` to read an existing file instead of creating one
3. In `virtual_memory.c`, allocate large blocks and observe address patterns
4. Create a program that demonstrates memory fragmentation
