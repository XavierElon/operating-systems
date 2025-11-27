#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * C REFRESHER:
 * - pid_t is a type alias (usually int) for process IDs
 * - fork() returns pid_t: >0 in parent (child's PID), 0 in child, -1 on error
 * - exit() terminates the process with a status code
 */
int main() {
    pid_t pid;

    printf("Before fork: PID = %d, PPID = %d\n", getpid(), getppid());

     // fork() creates a copy of the current process
    // Both parent and child continue execution from this point
    
}