#include <stdio.h>
#include "student.h"

int main(int argc, char*argv[])
{
	struct student record;
	FILE *fp;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s [file name]\n", argv[0]);
		return 1;
	}

	if((fp = fopen(argv[1], "rb")) == NULL) {
 		fprintf(stderr, "file open error\n");
		return 2;
	}

	printf("---------------------------------\n");
	printf("%10s %6s %6s\n", "StudentID", "Name", "Score");
	printf("---------------------------------\n");
				
	while(fread(&record, sizeof(record), 1,fp) >0)
		if(record.id != 0)
		printf("%10d %6s %6d\n ", record.id, record.name, record.score);


	printf("----------------------------------\n");

	fclose(fp);
	return 0;
}

