#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int  id;
	char c;
	FILE *fp;
	struct student rec;

	if(argc != 2) {
		fprintf(stderr, "Usage : %s file\n", argv[0]);
		return 1;
	}

	if((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "file open error\n");
		return 2;
	}

	do {
		printf("\nStudentID:");
		if (scanf("%d", &id) == 1) {
			fseek(fp, (id-START_ID)*sizeof(rec), SEEK_SET);
			if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
				printf("studentID: %8d\t name:%4s\t score:%4d\n",
						rec.id, rec.name, rec.score);
			else printf("no record %d \n", id);
		}
		else printf("input error");
		
		long size;
		size = ftell(fp);
		printf("location : %ld \n", size); 
		printf("continue?(Y/N)");
		scanf(" %c", &c);
	} while(c == 'Y');

	fclose(fp);
	return 0;
}

