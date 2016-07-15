/* CS261- Assignment 1 - Q.4*/
/* Name: Sky Wilson
 * Date: 03/31/2015
 * Solution description: This program includes a struct student that contains 2 int member variables (id and score). There is also a sort() return type void, that sorts the score member variables of instances of student structs. The main function declares an int which is assigned the value that represents the number student instances to be instantiated. Memory is statically allocated for the number of students instances. Random integers are assigned to each student instance's member variables (id(a value 1000-1100) and score(a value 0-100)). The member variables of each student instance is printed to the user. The sort function is invoked and is passed the struct student array and the int that represents the number of students. The scores of each student instance of the struct student array, are sorted in ascending order. The sorted scores are then printed once more.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
	printf("SORTING STUDENT SCORES IN ASCENDING ORDER\n\n");
	
	int temp;
	for(int counter = 0; counter < n; counter++){
		for(int i = 0; i < (n - 1); i++){
			if(students[i].score > students[i + 1].score){
				temp = students[i + 1].score;
				students[i + 1].score = students[i].score;
				students[i].score = temp;
			}
		}
	}		
}

int main(){
    /*Declare an integer n and assign it a value.*/
    	int n = 10;	/* n == number of students */
    /*Allocate memory for n students using malloc.*/
    	struct student *studentList = malloc(n * sizeof(int));
    /*Generate random IDs and scores for the n students, using rand().*/
    	srand(time(NULL));
	for(int i = 0; i < n; i++){
		studentList[i].id = (rand() % (n + 100) + 1000);
		studentList[i].score = (rand() % 100 + 1);
	}
    /*Print the contents of the array of n students.*/
	for(int i = 0; i < n; i++){
		printf("STUDENT ID: %d\n", studentList[i].id);
		printf("STUDENT SCORE: %d\n\n", studentList[i].score);
	}
    /*Pass this array along with n to the sort() function*/
		sort(studentList, n);    
    /*Print the contents of the array of n students.*/
	for(int i = 0; i < n; i++){
		printf("STUDENT ID: %d\n", studentList[i].id);
		printf("STUDENT SCORE: %d\n\n", studentList[i].score);
	}
    return 0;
}

