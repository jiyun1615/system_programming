#include <stdio.h>
#include <signal.h>

struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo);

int main(void)
{
	newact.sa_handler = sigint_handler;
	sigfillset(&newact.sa_mask);


	sigaction(SIGINT, &newact, &oldact);
	while(1)
	{
		printf("Press Ctrl-C !\n");
		sleep(1);
	}
}

void sigint_handler(int signo)
{
	printf("handle the signal %d times! \n", signo);
	printf("quit if you press it agian.\n");
	sigaction(SIGINT, &oldact, NULL);
}

