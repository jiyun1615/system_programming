#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system(const char *cmdstring)
{
	pid_t pid;
	int status;

	if(cmdstring == NULL)
		return 1;
	pid = fork();
	
	if(pid == -1) {
		return -1;
	}

	if(pid == 0) {
		execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
		_exit(127);
	}

	do{
		if(waitpid(pid, &status, 0) == -1) {
			if(errno != EINTR)
				return -1;
		}
		else
			return status;
	}while(1);
}

int main(int argc, char *argv[]) {
	int status;

	status = system("ls -asl");

	if(status == -1)
		perror("system() erro");
	printf("exit cod: %d \n", WEXITSTATUS(status));
}

