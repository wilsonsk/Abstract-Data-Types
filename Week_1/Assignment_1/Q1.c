/* CS261- Assignment 1 - Q.1*/
/* Name: Sky Wilson
 * Date: 03/30/2015
 * Solution description: This program utilizes a struct, student, with id and score as int member variables. The program then has 5 functions declared that take a pointer to a student object as a parameter.
The first function called allocate() statically declares memory for 10 student objects. generate() assigns a random integer to the id member variable and score member variable of each of the 10 student objects.
output() prints to the terminal, the id's and score's of the ten student objects.  summary() calculates and prints the minimum, maximum and average score of the 10 student objects. And finally, deallocate() 
frees the memory held by the student pointers and returns that memory to the heap.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	int numStudents = 10;
	struct student *myStudents = malloc(numStudents * sizeof(struct student));
     /*return the pointer*/
	return myStudents;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	srand(time(NULL));     
	int numStudents = 10;
	for(int i = 0; i < numStudents; i++){
		students[i].id += (rand() % numStudents + 1);
	}
	
	int scoreRange = 100;
	for(int i = 0; i < numStudents; i++){
		students[i].score += (rand() % scoreRange + 1);
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	
	int numStudents = 10;
	for(int i = 0; i < numStudents; i++){
		int printedID_1 = (i + 1);
		printf("STUDENT %d ID: %d\n", printedID_1, students[i].id);
	}
	
	for(int i = 0; i < numStudents; i++){
		int printedID_2 = (i + 1);
		printf("STUDENT %d SCORE: %d\n", printedID_2, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	
	int numStudents = 10;
    /* MINIMUM */
	int minimum = students[0].score;
	for(int i = 0; i < numStudents; i++){
		if(students[i].score < minimum){
			minimum = students[i].score;
		}
	}
	printf("MINIMUM SCORE: %d\n", minimum);

    /* MAXIMUM */
	int maximum = students[0].score;
	for(int i = 0; i < numStudents; i++){
		if(students[i].score > maximum){
			maximum = students[i].score;
		}
	}
	printf("MAXIMUM SCORE: %d\n", maximum);

     /* AVERAGE */
	int average;
	for(int i = 0; i < numStudents; i++){
		average += students[i].score;
	}
	average /= 10;
	printf("AVERAGE SCORE: %d\n", average);	     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
   
	stud = allocate();
 
    /*call generate*/
   
	generate(stud);
 
    /*call output*/

	output(stud);
    
    /*call summary*/
   
	summary(stud);
	 
    /*call deallocate*/

	deallocate(stud);

    return 0;
}

