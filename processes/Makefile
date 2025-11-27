# C REFRESHER: Makefiles automate compilation
# Format: target: dependencies
#         <TAB>command

CC = gcc
CFLAGS = -Wall -Wextra -g # -g adds debugging symbols
TARGETS = fork wait exec

# Default target (run: make)
all: $(TARGETS)

# Build each program
fork: fork.c
	$(CC) $(CFLAGS) -o fork fork.c

wait: wait.c
	$(CC) $(CFLAGS) -o wait wait.c

exec: exec.c
	$(CC) $(CFLAGS) -o exec exec.c

# Clean up compiled files
clean:
	rm -f $(TARGETS)

run-fork: fork
	@echo "=== Running fork file ==="
	./fork

run-wait: wait
	@echo "=== Running wait file ==="
	./wait

run-exec: exec
	@echo "=== Running exec file ==="
	./exec

# Run all examples (for testing)
run: all
	@echo "=== Running fork file ==="
	./fork
	@echo "=== Running wait file ==="
	./wait
	@echo "=== Running exec file ==="
	./exec

.PHONY: all clean run