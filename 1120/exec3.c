#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int child, pid, status;
	pid = fork();

	if(pid == 0)
	{
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "%s:not available\n", argv[1]);
	}
	else {
		child = wait(&status);
		printf("child process of [%d], %d done \n", getpid(), pid);
		printf("\texit code %d \n", status >>8);
	}
}


//I'm just writing somethis stange 
//Cannot understand why professor just give us a minute, and want lots of effort...
//Guess he is not possible to understand student.
