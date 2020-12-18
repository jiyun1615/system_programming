#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void intHandler(int signo);

int main()
{
	signal (SIGINT, intHandler);

	while(1)
		pause();

	printf("not executed \n");
}

void intHandler(int signo)
{
	printf("handle the interrupt signal \n");
	printf("signal number: %d\n", signo);
	exit(0);
}

