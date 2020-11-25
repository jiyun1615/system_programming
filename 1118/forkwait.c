#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid, child, status;

	printf("parent process [%d] start \n", getpid());
	pid = fork();
	if(pid == 0) {
		printf("Child process [%d] start \n", getpid());
		exit(1);
	}

	child = wait(&status);
	printf("child process of [%d], %d done \n", getpid(), child);
	printf("\t exit code: %d\n ", status>>8);
}
