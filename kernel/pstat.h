struct pstat {
  int pid;     // Process ID
  enum procstate state;  // Process state
  uint64 size;     // Size of process memory (bytes)
  int ppid;        // Parent process ID
  char name[16];   // Parent command name
  int priority;	   // priority of the process
  uint64 readytime; // ready time
  int cputime;		    //cputime 
};
struct rusage {
  uint cputime;
};
