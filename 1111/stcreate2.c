#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[])
{
	struct student rec;
	FILE *fp;

	if(argc != 2){
		fprintf(stderr, "Usage :%s [file name \n", argv[0]);
		return 1;
	}

	fp = fopen(argv[1], "wb");


	printf("%-9s %-7s %-4s\n", "studentID", "name", "score");
	while(scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3) {
		fseek(fp, (rec.id - START_ID) * sizeof(rec), SEEK_SET);
		fwrite(&rec, sizeof(rec), 1, fp );
	}

	fclose(fp);
	return 0;
}

