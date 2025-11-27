#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> // wait, waitpid
#include <unistd.h>

/**
 * C REFRESHER:
 * - wait() blocks until a child process terminates
 * - wait() returns the child's PID, or -1 on error
 * - &status is passing address of status variable (pointer)
 * - WIFEXITED(status) is a macro that checks if child exited normally
 * - WEXITSTATUS(status) extracts the exit code
 */

int main() {
  pid_t pid, wpid;
  int status;

  printf("Parent PID: %d\n", getpid());

  pid = fork();

  if (pid < 0) {
    perror("fork failed");
    exit(1);
  }

  if (pid == 0) {
    // CHILD: Do some work then exit
    printf("Child (PID %d) starting work...\n", getpid());
    sleep(2); // Simulate work (sleep for 2 seconds)
    printf("Child (PID %d) finished work\n", getpid());
    exit(42); // Exit with custom status code
  } else {
    // PARENT: Wait for child to finish
    printf("Parent waiting for child (PID %d) to finish...\n", pid);

    // wait() BLOCKS until child terminates
    // &status passes the address of status variable
    // This is needed because wait() modifies status to contain exit info
    wpid = wait(&status);

    if (wpid < 0) {
      perror("wait failed");
      exit(1);
    }

    printf("Parent (PID %d) got child (PID %d) status: %d\n", getpid(), wpid,
           status);

    // Check HOW the child terminated
    if (WIFEXITED(status)) {
      // Child exited normally
      printf("Child exited normally with status: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      // Child was killed by a signal
      printf("Child was killed by signal: %d\n", WTERMSIG(status));
    }
  }
  return 0;
}