#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

/**
 * OS CONCEPT:
 * - Memory-mapped files let you treat files as memory
 * - OS handles buffering and caching automatically
 * - Very efficient for large files or shared memory
 *
 * C REFRESHER:
 * - open() returns file descriptor (int)
 * - ftruncate() sets file size
 * - close() closes file descriptor
 */

int main() {
  const char *filename = "mmapped_file.txt";
  size_t size = 1024;
  int fd;
  void *ptr;

  printf("=== Memory-Mapped File Example ===\n");

  // Create/open file with read/write permissions
  // O_RDWR = read and write
  // O_CREAT = create if doesn't exist
  // 0644 = file permissions (rw-r--r--)
  fd = open(filename, O_RDWR | O_CREAT, 0644);

  if (fd == -1) {
    perror("open failed");
    exit(1);
  }

  if (ftruncate(fd, size) == -1) {
    perror("ftruncate failed");
    close(fd);
    exit(1);
  }

  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  if (ptr == MAP_FAILED) {
    perror("mmap failed");
    close(fd);
    exit(1);
  }

  // Close file descriptor - we don't need it anymore
  // (mmap keeps the mapping alive)
  close(fd);

  printf("File mapped at address: %p\n", ptr);

  // Write to file through memory
  char *data = (char *)ptr;
  const char *message = "This is written through memory mapping!";
  strncpy(data, message, size - 1);
  data[size - 1] = '\0'; // Ensure null-termination

  // Force changes to be written to disk
  // MS_SYNC = synchronous write (wait for completion)
  if (msync(ptr, size, MS_SYNC) == -1) {
    perror("msync failed");
  }

  printf("Written to file via memory: %s\n", data);

  printf("Reading back: %s\n", (char *)ptr);

  // Unmap and cleanup
  if (munmap(ptr, size) == -1) {
    perror("munmap failed");
    exit(1);
  }

  printf("File unmapped. Check '%s' - it should contain our data!\n", filename);

  return 0;
}