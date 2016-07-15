/* CS261- Assignment 1 - Q.3*/
/* Name: Sky Wilson
 * Date: 03/31/2015
 * Solution description: A function called sort returns type void and takes an int pointer and an int value as parameters. This function sorts the values of the elements of the integer pointer array.
In the main function of this program, an int is delcared and assigned a value 20. Memory is statically allocated (enough for n ints) via malloc(). The int array is filled (elemnts of the array are assigned) with random ints (0-20). The values of the array are printed to the user. The sort() is invoked, and the int array, thus, sorted. The array is then printed once more to display the sorted values of the array. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
	printf("SORTING ARRAY ELEMENTS IN ASCENDING ORDER\n\n");
	int temp;
	for(int counter = 0; counter < n; counter++){
		for(int i = 0; i < (n - 1); i++){
			if(number[i] > number[i + 1]){
				temp = number[i + 1];
				number[i + 1] = number[i];
				number[i] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
   	int n = 20; 
    /*Allocate memory for an array of n integers using malloc.*/
    	int *array = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		array[i] = (rand() % n + 1);
	}    
    /*Print the contents of the array.*/
	for(int i = 0; i < n; i++){
		printf("VALUE OF ARRAY ELEMENT: %d = %d\n", i, array[i]);
	}
    /*Pass this array along with n to the sort() function of part a.*/
	sort(array, n);    
    /*Print the contents of the array.*/    
    	for(int i = 0; i < n; i++){
		printf("VALUE OF ARRAY ELEMENT: %d = %d\n", i, array[i]);
	}

    return 0;
}

