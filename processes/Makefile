# C REFRESHER: Makefiles automate compilation
# Format: target: dependencies
#         <TAB>command

CC = gcc
CFLAGS = -Wall -Wextra -g # -g adds debugging symbols
TARGETS = fork

# Default target (run: make)
all: $(TARGETS)

# Build each program
fork: fork.c
	$(CC) $(CFLAGS) -o fork fork.c

# Clean up compiled files
clean:
	rm -f $(TARGETS)

# Run all examples (for testing)
run: all
	@echo "=== Running fork file ==="
	./fork

.PHONY: all clean run