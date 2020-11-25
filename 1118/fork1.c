#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid;
	printf("process: [%d] start \n", getpid());
	pid = fork();
	printf("[rpcess: [%d], return value: [%d] \n", getpid(), pid);
}
