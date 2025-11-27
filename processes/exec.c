#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * C REFRESHER:
 * - exec family replaces current process image with new program
 * - exec never returns (unless error)
 * - execvp() takes program name and array of arguments
 * - execvp() searches PATH for the program
 * - Last argument must be NULL (C string array terminator)
 */

int main() {
  pid_t pid;

  printf("Before fork: PID = %d\n", getpid());

  pid = fork();

  if (pid < 0) {
    perror("fork failed");
    exit(1);
  }

  if (pid == 0) {
    // CHILD: Replace ourselves with a new program

    // execvp() arguments:
    // 1. "ls" - program to execute (searches PATH)
    // 2. argv - array of arguments (program name + flags + NULL)

    // C REFRESHER: Array initialization
    // This creates: {"ls", "-l", "-a", NULL}
    char *args[] = {"ls", "-l", "-a", NULL};

    printf("Child (PID %d) about to exec 'ls -l -a'\n", getpid());

    // execvp replaces current process with ls
    // If successful, this line and everything after never executes
    execvp("ls", args);

    // If execvp fails, it will never reach here
    perror("execvp failed");
    exit(1);
  } else {
    // PARENT: Wait for child to finish
    int status;
    wait(&status);
    printf("Parent (PID %d) got child (PID %d) status: %d\n", getpid(), pid,
           status);
  }

  return 0;
}