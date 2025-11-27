#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * C REFRESHER:
 * - getpid() returns current process ID (unistd.h)
 * - getppid() returns parent process ID
 * - getuid() returns user ID
 * - getgid() returns group ID
 * - These functions don't take arguments and always succeed
 */

int main() {
  pid_t pid, ppid;
  uid_t uid, euid; // User ID types
  gid_t gid, egid; // Group ID types

  // Get process IDs
  pid = getpid();
  ppid = getppid();

  // Get user and group IDs
  uid = getuid();
  euid = geteuid();
  gid = getgid();
  egid = getegid();

  printf("=== Process Information ===\n");
  printf("Process ID (PID):       %d\n", pid);
  printf("Parent Process ID:      %d\n", ppid);
  printf("Real User ID:           %d\n", uid);
  printf("Effective User ID:      %d\n", euid);
  printf("Real Group ID:          %d\n", gid);
  printf("Effective Group ID:     %d\n", egid);

  // Demonstrate parent-child relationship
  printf("\n=== Creating Child Process ===\n");
  pid_t child_pid = fork();

  if (child_pid < 0) {
    perror("fork failed");
    exit(1);
  }

  if (child_pid == 0) {
    // Child
    printf("\n[CHILD]\n");
    printf("My PID:      %d\n", getpid());
    printf("Parent PID:  %d (should match parent's PID above)\n", getppid());
    exit(0);
  } else {
    // Parent
    wait(NULL);
    printf("\n[PARENT]\n");
    printf("My PID:      %d\n", getpid());
    printf("Child PID:   %d (should match child's PID above)\n", child_pid);
    exit(0);
  }
  return 0;
}