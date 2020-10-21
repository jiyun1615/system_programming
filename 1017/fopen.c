#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	
	if((fd = open (argv[1], O_RDWR)) == -1)
		printf("open file error\n");
	else printf("open file %s : %d\n", argv[1], fd);

	close(fd);
	
	exit(0);
}

