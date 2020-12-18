#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;
void alarmHandler();

int main(int argc, char * argv[])
{
	int child, status, limit;

	signal(SIGALRM, alarmHandler);
	sscanf(argv[1], "%d", &limit);
	alarm(limit);

	pid = fork();
	if(pid == 0) {
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s:cannot be executed. \n", argv[1]);
	} else {
		child = wait(&status);
		printf("the child process of[%d], %d finished. \n", getpid(), child);
	}
}

void alarmHandler()
{
	printf("[alarm] the child process %d, timeout. \n", pid);
	kill(pid, SIGINT);
}

