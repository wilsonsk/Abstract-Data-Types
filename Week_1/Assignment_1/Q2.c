/* CS261- Assignment 1 - Q.2*/
/* Name: Sky Wilson
 * Date: 03/30/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
   	*a /= 2; 
    /*Set b to half its original value*/
    	*b /= 2;
    /*Assign a+b to c*/
    	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;    
    /*Print the values of x, y and z*/
    	printf("VALUE OF X = %d\n", x);
    	printf("VALUE OF Y = %d\n", y);
    	printf("VALUE OF Z = %d\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    	int *ptr_x = &x;
	int *ptr_y = &y;
	int functionValue;
	functionValue = foo(ptr_x, ptr_y, z);
    /*Print the value returned by foo*/
	printf("VALUE RETURNED BY foo() = %d\n", functionValue);    
    /*Print the values of x, y and z again*/
    	printf("VALUE OF X = %d\n", x);
    	printf("VALUE OF Y = %d\n", y);
    	printf("VALUE OF Z = %d\n", z);
    /*Is the return value different than the value of z?  Why?*/
	/* ANSWER: The return value of foo() is differenct than the value of z. This is because z was passed into foo as an argument, by value. foo() then created a new variable that was assigned the value of z.This copied variable is then reassigned the value of the sum of a + b. This summed value is then returned to the main function where it was invoked, and assigned to a local variable called functionValue. functionValue and z have 2 different values. z retains its original value, while functionValue (value returned by foo()) is a different variable that was initially assigned the value of z but then later re assigned the sum of a and b. */    	
	return 0;
}
    
    

