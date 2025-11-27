#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

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
  pid = fork();

  // ERROR HANDLING: fork() returns -1 if it fails
  if (pid < 0) {
    perror("fork failed");
    exit(1);
  }

  // After fork(), we're in BOTH processes
  // But pid has different values:
  // - In parent: pid = child's process ID (positive number)
  // - In child:  pid = 0
  // - On error:  pid = -1 (already handled above)
  if (pid == 0) {
    // CHILD PROCESS pid == 0
    printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
    printf("Child process: I'm the child!\n");
    exit(0);
  } else {
    // PARENT PROCESS pid > 0
    printf("Parent process: PID = %d, PPID = %d\n", getpid(), getppid());
    printf("Parent: fork() returned %d (child's PID)\n", pid);
  }

  printf("This prints in: %s (PID: %d)\n", (pid == 0) ? "child" : "parent",
         getpid());

  return 0;
}