#include <stdio.h>
#include <stdlib.h>

struct student {
	int id;
	char name[20];
};

int main()
{
	struct student *p;
	int n, i;

	printf("The number of student : ");
	scanf("%d", &n);
	if(n<= 0) {
		fprintf(stderr, "error : invalid number \n");
		fprintf(stderr, "exit the program \n");
		exit(1);
	}

	p = (struct student *) malloc (n * sizeof(struct student));
	if(p == NULL) {
		perror("malloc");
		exit(2);
	}

	printf("Enter %d student id and name. \n", n);
	for(i=0; i<n; i++)
		scanf("%d %s\n", &p[i].id, p[i].name);

	printf("\n* student info(inreverse order) *\n");
	for(i=n-1; i>= 0; i--)
   		printf("%d %s\n", p[i].id, p[i].name);

	printf("\n");
	exit(0);
}

 

