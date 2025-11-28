#include <fcntl.h> // open, O_RDWR, O_CREAT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // strcpy, strlen
#include <sys/mman.h> // mmap, munmap
#include <unistd.h>   // close, ftruncate

/**
 * C REFRESHER:
 * - mmap() maps files or anonymous memory into virtual address space
 * - void * means "pointer to any type" (generic pointer)
 * - PROT_READ, PROT_WRITE are permission flags
 * - MAP_SHARED means changes are visible to other processes
 * - munmap() unmaps the memory
 *
 * OS CONCEPT:
 * - mmap() creates a mapping in virtual memory
 * - The OS manages physical memory allocation (lazy loading)
 * - Reading/writing to mapped memory may trigger page faults
 */

int main() {
  // Size of memory to map (1 page = typically 4KB)
  size_t size = 4096;
  void *ptr;

  printf("=== Memory Mapping Example ===\n");

  // MAP_ANONYMOUS creates memory not backed by a file
  // -1 means no file descriptor (since it's anonymous)
  // PROT_READ | PROT_WRITE = readable and writable
  // MAP_PRIVATE = changes only visible to this process
  // MAP_ANONYMOUS = allocate memory (not from a file)
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
             -1, 0);

  if (ptr == MAP_FAILED) {
    perror("mmap failed");
    exit(1);
  }

  printf("Memory mapped at address: %p\n", ptr);

  // C REFRESHER:
  // - (char *) casts void* to char* (pointer to bytes)
  // - We can now treat ptr as a string buffer
  char *str = (char *)ptr;

  // Write to the mapped memory
  strcpy(str, "Hello from mmap!");
  printf("Written to memory: %s\n", str);

  // Read back the data
  printf("Reading back: %s\n", str);
  printf("Memory address: %p\n", ptr);
  printf("Size of memory: %zu bytes\n", size);

  // Unmap the memory when done
  // C REFRESHER: munmap() takes address and size
  if (munmap(ptr, size) == -1) {
    perror("munmap failed");
    exit(1);
  }

  printf("Memory unmapped\n");

  // NOTE: After munmap, accessing ptr would cause a segmentation fault!

  return 0;
}