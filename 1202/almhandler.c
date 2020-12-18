#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler();

int main()
{
	int sec = 0;

	signal(SIGALRM,alarmHandler);
	alarm(5);
	printf("infinite loop \n");
	while(1) {
		sleep(1);
		printf("after %dsec \n", ++sec);
	}
	printf("not executed \n");
}

void alarmHandler()
{
	printf("wake up! \n");
	exit(0);
}

