#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"
int
main(int argc, char **argv)
{
  printf("Starting PS");
  struct pstat uproc[NPROC];
  int nprocs;
  int i;
  char *state;
  static char *states[] = {
    [SLEEPING]  "sleeping",
    [RUNNABLE]  "runnable",
    [RUNNING]   "running ",
    [ZOMBIE]    "zombie  "
  };

  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);
  printf("pid\tstate\tsize\tppid\tname\tpriority\tcputime\tage\n");
  for (i=0; i<nprocs; i++) {
    state = states[uproc[i].state];
    if(uproc[i].state == RUNNING){
        uint64 current_time = uptime();
        uint64 age = current_time - uproc[i].readytime;
        printf("%d\t%s\t%l\t%d\t%s\t%d\t%d\t%d\t%l\n", uproc[i].pid, state,
                   uproc[i].size, uproc[i].ppid, uproc[i].name, uproc[i].priority, uproc[i].cputime, age);
    }else{

    printf("%d\t%s\t%l\t%d\t%s\t%d\t%d\n", uproc[i].pid, state,
                   uproc[i].size, uproc[i].ppid, uproc[i].name, uproc[i].priority, uproc[i].cputime);
   }
  }
  exit(0);
}
