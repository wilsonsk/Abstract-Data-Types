#include <stdlib.h>
#include <stdio.h>

typedef struct{
	int id;
}Student;

void foo(Student* a){
	printf("ID: %d\n\n", a->id);
}

int main()
{
	int numStudents = 10;

	Student *myStudents = malloc(numStudents * sizeof(Student));

	foo(&myStudents[0]);

	return 0;
}
