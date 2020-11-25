#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int status;

	if((status = system("date")) < 0)
		perror("system() error");
	printf("exit coe : %d\n", WEXITSTATUS(status));

	if((status = system("hello")) < 0)
         perror("system() error");
     printf("exit coe : %d\n", WEXITSTATUS(status));
      
	 if((status = system("who; exit 44")) < 0)
         perror("system() error");
     printf("exit coe : %d\n", WEXITSTATUS(status));
}


