#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

/**
 * OS CONCEPT: Virtual Memory
 * - Each process has its own virtual address space
 * - Virtual addresses are mapped to physical addresses by OS
 * - Pages are the unit of virtual memory (typically 4KB)
 * - Not all virtual memory needs physical memory (lazy allocation)
 *
 * This program demonstrates:
 * - Stack variables (local variables)
 * - Heap variables (malloc)
 * - Code/text segment (functions)
 * - Virtual memory layout
 */

int global_var = 42;         // Stored in data segment
static int static_var = 100; // Also in data segment

void function_address_demo() {
  // C REFRESHER:
  // - &variable gets address of variable
  // - %p prints pointer address
  // - Functions have addresses too (code segment)

  printf("Function address: %p\n", (void *)function_address_demo);
  //   printf("main() address:   %p\n", (void *)main);
}

void stack_vs_heap() {
  printf("\n=== Stack vs Heap ===\n");

  // Stack variable (local variable)
  int stack_var = 10;
  printf("Stack variable address: %p (value: %d)\n", (void *)&stack_var,
         stack_var);

  // Heap variable (dynamically allocated)
  int *heap_var = (int *)malloc(sizeof(int));
  *heap_var = 20;
  printf("Heap variable address:  %p (value: %d)\n", (void *)heap_var,
         *heap_var);

  // C REFRESHER:
  // - Stack grows downward (high to low addresses)
  // - Heap grows upward (low to high addresses)
  // - They grow toward each other

  free(heap_var);
}

void virtual_address_space() {
  printf("\n=== Virtual Address Space Layout ===\n");

  // Show typical memory layout (approximate)
  printf("High addresses (0x7fff...)\n");
  printf("  ↓ Stack (grows down)\n");
  printf("  ↓\n");
  printf("  ↓ (unused)\n");
  printf("  ↓\n");
  printf("  ↑ Heap (grows up)\n");
  printf("  ↑\n");
  printf("  ↑ Data segment (global/static variables)\n");
  printf("Low addresses (0x...)\n");
  printf("  ↑ Text segment (code)\n");

  printf("\nActual addresses in this process:\n");
  printf("Global variable:  %p\n", (void *)&global_var);
  printf("Static variable:  %p\n", (void *)&static_var);

  int local = 5;
  printf("Local variable:   %p\n", (void *)&local);

  void *heap = malloc(10);
  printf("Heap allocation:  %p\n", heap);
  free(heap);
}

void page_size_demo() {
  printf("\n=== Page Size (Virtual Memory Unit) ===\n");

  // C REFRESHER: sysconf() gets system configuration values
  // _SC_PAGESIZE gets the system page size
  long page_size = sysconf(_SC_PAGESIZE);

  printf("System page size: %ld bytes (%ld KB)\n", page_size, page_size / 1024);
  printf("Virtual memory is managed in pages of this size\n");
  printf("mmap() and malloc() work in page-sized units\n");
}

int main() {
  printf("=== Virtual Memory Concepts ===\n");

  printf("Global variable address: %p (value: %d)\n", (void *)&global_var,
         global_var);
  printf("Static variable address: %p (value: %d)\n", (void *)&static_var,
         static_var);

  function_address_demo();
  stack_vs_heap();
  virtual_address_space();
  page_size_demo();

  printf("\n=== Key Virtual Memory Concepts ===\n");
  printf("1. Each process has private virtual address space\n");
  printf("2. OS maps virtual → physical addresses\n");
  printf("3. Pages are units of virtual memory\n");
  printf("4. Stack and heap grow toward each other\n");
  printf("5. Not all virtual memory has physical memory yet\n");

  return 0;
}