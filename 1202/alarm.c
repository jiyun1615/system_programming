#include <unistd.h>
#include <stdio.h>

int main()
{
	int sec = 0;

	alarm(5);
	printf("infinite loop \n");
	while(1) {
		sleep(1);
		printf("after %dsec \n", ++sec);
	}
	printf("not executed. \n");
}

