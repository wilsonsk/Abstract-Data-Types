/* CS261- Assignment 1 - Q. 0*/
/* Name: Sky Wilson
 * Date: 3/30/2105
 * Solution description: The main function includes a subroutine that declares an integer variable, x, and then also prints the ADDRESS of variable x via the printf() function. A function called fooA(int* iptr) prints (via printf()) the value pointed to be iptr*, the address pointed to by iptr*, and the address of iptr* itself. The function fooA(int* iptr) 
 */
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     
	printf("VALUE POINTED TO BY iptr*(value of x): %d\n\n", *iptr);

     /*Print the address pointed to by iptr*/

	printf("ADDRESS POINTED TO BY iptr*(address of x): %p\n\n", &iptr);
     
     /*Print the address of iptr itself*/	
		
	printf("ADDRESS OF iptr* ITSELF(pointer to x): %p\n\n", &(*iptr));
}

int main()
{
	int x = 5;
	printf("ADDRESS of x: %p\n\n", &x);

	int *ptr_x = &x;
	fooA(ptr_x);

	return 0;
}
