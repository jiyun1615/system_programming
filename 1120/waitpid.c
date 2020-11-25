#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid1, pid2, child, status;

	printf("parent process [%d] start \n", getpid());
	pid1 = fork();
	if(pid1 == 0) {
		printf("Child process #1 [%d] start \n", getpid());
		sleep(1);
		printf("Child process #1 [%d] done \n", getpid());
		exit(1);
	}
	
	pid2 = fork();
	

	if(pid2 == 0) {
	   	printf("Child process #2 [%d] start \n", getpid());
        sleep(3);
        printf("Child process #2 [%d] done \n", getpid());
        exit(2);
      }
 

	child = waitpid(pid2, &status, 0);
	printf("child process of [%d], %d done \n", getpid(), child);
	printf("\t exit code: %d\n ", status>>8);
}
