# C REFRESHER: Makefiles automate compilation
# Format: target: dependencies
#         <TAB>command

CC = gcc
CFLAGS = -Wall -Wextra -g # -g adds debugging symbols
TARGETS = fork wait

# Default target (run: make)
all: $(TARGETS)

# Build each program
fork: fork.c
	$(CC) $(CFLAGS) -o fork fork.c

wait: wait.C
	$(CC) $(CFLAGS) -o wait wait.c

# Clean up compiled files
clean:
	rm -f $(TARGETS)

# Run all examples (for testing)
run: all
	@echo "=== Running fork file ==="
	./fork
	@echo "=== Running wait file ==="
	./wait

.PHONY: all clean run