#ifndef	STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>

typedef struct Student{
	int id;
	char name[40];
}Student;

void printStudent(Student *s){
	int c = 10;
        printf("Name of student: %s\n", s->name);
        printf("ID of student: %d\n", s->id);
        printf("Inside printStudent, c = %d\n\n", c);
}

#endif	/*!STUDENT_H*/
