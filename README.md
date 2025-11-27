Program Structure

os-learning/
├── README.md
├── Makefile
├── 01-processes/
│ ├── fork_example.c
│ ├── exec_example.c
│ ├── wait_example.c
│ └── process_info.c
├── 02-memory/
│ ├── memory_mapping.c
│ ├── heap_management.c
│ └── virtual_memory.c
├── 03-file-systems/
│ ├── file_operations.c
│ ├── directory_traversal.c
│ └── permissions.c
├── 04-ipc/
│ ├── pipes.c
│ ├── shared_memory.c
│ └── signals.c
├── 05-threading/
│ ├── thread_basics.c
│ ├── mutex_example.c
│ └── condition_variables.c
└── 06-system-calls/
├── syscall_wrapper.c
└── resource_limits.c

Proposed starting modules:

1. Process Management (01-processes/) — Covers:
   Process creation with fork()
   Process execution with exec() family
   Process synchronization with wait()/waitpid()
   Process information (getpid(), getppid(), etc.)
1. Memory Management (02-memory/) — Covers:
   Memory mapping with mmap()
   Heap allocation (malloc()/free() internals)
   Virtual memory concepts
1. File Systems (03-file-systems/) — Covers:
   File I/O (open(), read(), write(), close())
   Directory operations
   File permissions and metadata
1. Inter-Process Communication (04-ipc/) — Covers:
   Pipes (pipe(), mkfifo())
   Shared memory (shm_open())
   Signals (signal(), sigaction())
1. Threading (05-threading/) — Covers:
   Thread creation with pthread
   Mutexes and locks
   Condition variables
1. System Calls (06-system-calls/) — Covers:
   Direct system call usage
   Resource limits (getrlimit(), setrlimit())
