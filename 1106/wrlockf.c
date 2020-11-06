#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student record;

	if(argc < 2) {
		fprintf(stderr, "Usage : %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	printf("\nStudent id:");
	while(scanf("%d", &id) == 1) {
		lseek(fd, (long) (id-START_ID) * sizeof(record), SEEK_SET);
		if(lockf(fd, F_LOCK, sizeof(record)) == -1) { 	/*write lock*/
			perror(argv[1]);
			exit(3);
		}

		if((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)){
			printf("Name:%s\t StudentId:%d\t Score:%d\n", record.name, record.id, record.score);
		}
		else printf("No record %d\n", id);

		printf("New score: ");
		scanf("%d", &record.score);
		lseek(fd, (long) -sizeof(record), SEEK_CUR);
		write(fd, (char *) &record, sizeof(record));

		lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
		lockf(fd, F_ULOCK, sizeof(record)); 	/*unlock*/
		printf("\nStudent id:");
		}
		close(fd);
		exit(0);
	}

