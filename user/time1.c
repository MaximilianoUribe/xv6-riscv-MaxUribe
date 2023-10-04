#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include <stddef.h>

int main(int argc, char ** argv){
	char *argv_arr[] = {(char *) NULL };
	if(argc != 2){
		exit(1);
	}

	uint start_time = uptime();
	int pid = fork();

	if(pid == 0){
		exec(argv[1], argv_arr);
		exit(0);
	}else if(pid == -1){
		exit(-1);
	}

	wait(&pid);
	uint end_time = uptime();
	uint total_time = end_time - start_time;
	printf("elapsed time: %d ticks",total_time);
	exit(0);
}
