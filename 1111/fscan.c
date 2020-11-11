#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student record;
	FILE *fp;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s [file name]\n", argv[0]);
		return 1;
	}

	fp = fopen(argv[1], "r");
	printf("%-9s %-7s %-4s\n", "StudentID", "Name", "Score");

	while(fscanf(fp, "%d %s %d", &record.id, record.name, &record.score) == 3)
		printf("%d %s %d\n", record.id, record.name, record.score);

	fclose(fp);
	return 0;
}

