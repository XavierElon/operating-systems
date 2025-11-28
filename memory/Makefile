# Memory Management Module Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
TARGETS = mmap mmap_file heap virtual_memory

# Default target
all: $(TARGETS)

# Build targets
mmap: mmap.c
	$(CC) $(CFLAGS) -o mmap mmap.c

mmapped_file: mmapped_file.c
	$(CC) $(CFLAGS) -o mmapped_file mmapped_file.c

heap: heap.c
	$(CC) $(CFLAGS) -o heap heap.c

virtual_memory: virtual_memory.c
	$(CC) $(CFLAGS) -o virtual_memory virtual_memory.c

# Individual run targets
run-mmap: mmap
	@echo "=== Running mmap ==="
	./mmap

run-mmapped-file: mmapped_file
	@echo "=== Running mmapped_file ==="
	./mmapped_file

run-heap: heap_basics
	@echo "=== Running heap_basics ==="
	./heap_basics

run-virtual: virtual_memory
	@echo "=== Running virtual_memory ==="
	./virtual_memory

# Clean up
clean:
	rm -f $(TARGETS) mmap_test.dat

# Run all examples
run: all
	@echo "=== Running mmap_example ==="
	./mmap_example
	@echo ""
	@echo "=== Running heap_basics ==="
	./heap_basics
	@echo ""
	@echo "=== Running virtual_memory ==="
	./virtual_memory
	@echo ""
	@echo "=== Running mmapped_file ==="
	./mmapped_file

.PHONY: all clean run run-mmap run-mmapped-file run-heap run-virtual