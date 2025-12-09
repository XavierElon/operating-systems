#include <stdio.h>
#include <stdlib.h> // malloc, free, calloc, realloc

/**
 * C REFRESHER:
 * - malloc(size) allocates size bytes, returns void*
 * - Returns NULL on failure (always check!)
 * - free(ptr) releases memory (must match malloc)
 * - Memory from malloc is NOT initialized (contains garbage)
 * - calloc() allocates and initializes to zero
 * - realloc() resizes existing allocation
 *
 * OS CONCEPT:
 * - Heap is a region of virtual memory managed by malloc
 * - malloc requests memory from OS using brk()/mmap() system calls
 * - free() returns memory to heap (may or may not return to OS)
 * - Memory fragmentation can occur over time
 */

void demonstrate_malloc() {
  printf("Demonstrating malloc\n");

  // Allocate memory for 10 integers
  // C REFRESHER: sizeof(int) returns size of int in bytes
  // sizeof is a compile-time operator (not a function)
  int *arr = (int *)malloc(10 * sizeof(int));

  if (arr == NULL) {
    perror("malloc failed");
    exit(1);
  }

  printf("Allocated array at address: %p\n", (void *)arr);

  for (int i = 0; i < 10; i++) {
    arr[i] = i * i;
  }

  printf("Array values:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d: %d\n", i, arr[i]);
  }

  free(arr);
  arr = NULL;
  printf("Memory freed\n");
}

void demonstrate_calloc() {
  printf("Demonstrating calloc\n");

  // calloc allocates AND initializes to zero
  // calloc(count, size) = allocate count * size bytes
  int *arr = (int *)calloc(5, sizeof(int));

  if (arr == NULL) {
    perror("calloc failed");
    exit(1);
  }

  printf("Allocated array at address: %p\n", (void *)arr);

  for (int i = 0; i < 5; i++) {
    printf("%d: %d\n", i, arr[i]);
  }

  free(arr);
  arr = NULL;
  printf("Memory freed\n");
}

void demonstrate_realloc() {
  printf("=== realloc() Example ===\n");

  // Start with small allocation
  int *arr = (int *)malloc(3 * sizeof(int));

  if (arr == NULL) {
    perror("malloc failed");
    exit(1);
  }

  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  printf("Original array (size 3): ");
  for (int i = 0; i < 3; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Resize to larger array
  // realloc may move memory to new location!
  int *new_arr = (int *)realloc(arr, 6 * sizeof(int));

  if (new_arr == NULL) {
    perror("realloc failed");
    free(arr); // Original still valid on failure
    exit(1);
  }

  arr = new_arr; // Use new pointer (may be same or different)

  // Initialize new elements
  arr[3] = 4;
  arr[4] = 5;
  arr[5] = 6;

  printf("Resized array (size 6): ");
  for (int i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("New address: %p\n", (void *)arr);

  free(arr);
  printf("Memory freed\n\n");
}

void demonstrate_memory_leak_example() {
  printf("=== Memory Leak Example (Demonstration) ===\n");

  // This allocates memory but doesn't free it
  // In a real program, this would be a "memory leak"
  int *leaked = (int *)malloc(100 * sizeof(int));

  printf("Allocated 100 integers but not freeing...\n");
  printf("This is a memory leak! (in real program)\n");
  printf("For demo purposes, we'll free it now:\n");

  // Actually free it for this demo
  free(leaked);
  printf("Freed (but normally this would be forgotten)\n\n");
}

int main() {
  demonstrate_malloc();
  demonstrate_calloc();
  demonstrate_realloc();
  demonstrate_memory_leak_example();

  printf("=== Key Takeaways ===\n");
  printf("1. Always check malloc/calloc/realloc return value\n");
  printf("2. Always free what you allocate\n");
  printf("3. Don't use memory after free()\n");
  printf("4. Don't free the same pointer twice\n");
  printf("5. malloc = uninitialized, calloc = zero-initialized\n");

  return 0;
}
