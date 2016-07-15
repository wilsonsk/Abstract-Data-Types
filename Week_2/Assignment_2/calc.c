#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}else if(strcmp(s, "pi") == 0){
		*num = 3.14159265;
		return 1;
	}
	else if(strcmp(s, "e") == 0){
		*num = 2.7182818;
		return 1;
	}else{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) <= 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}	
	double sum = 0;
	double addend_a = 0;
	double addend_b = 0;	
	addend_b = topDynArr(stack);
	popDynArr(stack);	
	addend_a  = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		sum = addend_a + addend_b;
		pushDynArr(stack, sum);
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) <= 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double difference = 0;
	double subtrahend = 0;
	double minuend = 0;
	subtrahend = topDynArr(stack);		
	popDynArr(stack);	
	minuend = topDynArr(stack);
	popDynArr(stack);	
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		difference = minuend - subtrahend;
		pushDynArr(stack, difference);
	}
}	

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	
	if(sizeDynArr(stack) <= 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double quotient = 0;
	double dividend = 0;
	double divisor = 0;
	divisor = topDynArr(stack);
	popDynArr(stack);
	dividend = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		quotient = dividend / divisor;
		pushDynArr(stack, quotient);
	}
}

void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) <= 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double product = 0;
	double multiplicand = 0;
	double multiplier = 0;
	multiplier = topDynArr(stack);
	popDynArr(stack);
	multiplicand = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		product = multiplicand * multiplier;
		pushDynArr(stack, product);
	}	
}

void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) <= 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double product = 0;
	double base = 0;
	double exponent = 0;
	exponent = topDynArr(stack);
	popDynArr(stack);
	base = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		product = base;
		for(int i = 1; i < exponent; i++){
			product *= base;
		}
		pushDynArr(stack, product);
	}
}

void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double product = 0;
	double base = 0;
	double exponent = 2;
	base = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		product = base;
		for(int i = 1; i < exponent; i++){
			product *= base;
		}
		pushDynArr(stack, product);
	}
}

void cube(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double product = 0;
	double base = 0;
	double exponent = 3;
	base = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		product = base;
		for(int i = 1; i < exponent; i++){
			product *= base;
		}
		pushDynArr(stack, product);
	}
}

void absoluteVal(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double abs = 0;
	double value = 0;
	value = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		if(value < 0){
			abs = fabs(value);
		}else{
			abs = value;
		}
		pushDynArr(stack, abs);
	}
}

void squareRoot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double radicand = 0;
	double principalSquareRoot = 0;
	radicand = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		principalSquareRoot = sqrt(radicand);	
		pushDynArr(stack, principalSquareRoot);
	}
}

void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double product = 0;
	double base = 2.7182818;
	double exponent = 0;
	exponent = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		product = base;
		for(int i = 1; i < exponent; i++){
			product *= base;
		}
		pushDynArr(stack, product);
	}
}

void naturalLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double naturalLog = 0;
	/* double base = 2.7182818; NATURAL LOG USES BASE e */
	double X = 0;
	X = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		naturalLog = log(X);
		pushDynArr(stack, naturalLog);
	}
}	

void logBaseTen(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if(sizeDynArr(stack) < 1){
		printf("ERROR: %d OPERAND: NOT ENOUGH OPERANDS TO PERFORM THIS OPERATION\n", sizeDynArr(stack));
	}
	double naturalLog = 0;
	/* double base = 10; BASE TEN LOG USES BASE 10 */
	double X = 0;
	X = topDynArr(stack);
	popDynArr(stack);
	if(isEmptyDynArr(stack) == 0){	
		printf("ERROR: TOO MANY OPERANDS FOR THIS OPERATION\n");
	}else if(isEmptyDynArr(stack) == 1){
		naturalLog = log10(X);
		pushDynArr(stack, naturalLog);
	}
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double* num = &result;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack
			
		if((strcmp(s, "+") == 0) && (isNumber(s, num) == 0)){
			add(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "-") == 0) && (isNumber(s, num) == 0)){
			subtract(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "/") == 0) && (isNumber(s, num) == 0)){
			divide(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "x") == 0) && (isNumber(s, num) == 0)){
			multiply(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "^") == 0) && (isNumber(s, num) == 0)){
			power(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "^2") == 0) && (isNumber(s, num) == 0)){
			square(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "^3") == 0) && (isNumber(s, num) == 0)){
			cube(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "abs") == 0) && (isNumber(s, num) == 0)){
			absoluteVal(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "sqrt") == 0) && (isNumber(s, num) == 0)){
			squareRoot(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "exp") == 0) && (isNumber(s, num) == 0)){
			exponential(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "ln") == 0) && (isNumber(s, num) == 0)){
			naturalLog(stack);
			printf("Operator: %s\n", s);
		}else if((strcmp(s, "log") == 0) && (isNumber(s, num) == 0)){
			logBaseTen(stack);
			printf("Operator: %s\n", s);
		}else if((isNumber(s, num) == 1)){
			pushDynArr(stack, result);
			printf("pushed %lf\n", result);
		}else{
			printf("ERROR: UNKNOWN OPERATOR OR OPERAND: %s\n", s);	
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	result = topDynArr(stack);
	printf("result = %lf\n\n", result);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

/* DEBUG: argc, argv: 
	for(int i = 1; i < argc; i++){
		printf("argc = %i ; argv[i] = %c", argc, argv[i]);	
	}
*/

	for(int i = 1; i < argc; i++){
		printf("argc = %i ; argv[i] = %s\n", argc, argv[i]);	
	}
	calculate(argc,argv);
	return 0;
}

