# Operating System Fundamentals - Learning Program

## Module 1: Process Management

### Learning Objectives

- Understand what a process is
- Learn to create processes with `fork()`
- Learn to replace process image with `exec()` family
- Learn to synchronize processes with `wait()`
- Understand parent-child relationships

### Files

- `fork_example.c` - Basic process creation
- `wait_example.c` - Parent-child synchronization
- `exec_example.c` - Replacing process with new program
- `process_info.c` - Inspecting process information

### Build & Run

make # Build all programs
make fork_example # Build specific program
make clean # Remove compiled files
make run # Build and run all examples### Exercises

1. Modify `fork_example.c` to create multiple children
2. In `wait_example.c`, what happens if parent doesn't wait?
3. Change `exec_example.c` to run a different program
4. Add error checking to all programs

### Key Concepts

- **Process**: Running instance of a program
- **PID**: Process ID (unique identifier)
- **PPID**: Parent Process ID
- **fork()**: Creates copy of current process
- **exec()**: Replaces current process with new program
- **wait()**: Parent waits for child to terminate
