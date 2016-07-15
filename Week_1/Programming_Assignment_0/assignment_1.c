#include <stdio.h>
#include <string.h>

typedef struct{
	double inches;
	double centimeters;
}User;

void getUserInches(User *a_1);
void getUserCentimeters(User *a_1);
void convertInchesToCentimeters(User *a_1);
void convertCentimetersToInches(User *a_1);

int main()
{
	User a;
	User *ptr_a = &a;
	getUserInches(ptr_a);
	convertInchesToCentimeters(ptr_a);
	
	getUserCentimeters(ptr_a);
	convertCentimetersToInches(ptr_a);

	return 0;
}

void getUserInches(User *a_1)
{
	printf("Enter inches to be converted to centimeters: ");
	scanf("%lf", &a_1->inches);
	printf("INPUT: %f inches \n", a_1->inches);
}

void getUserCentimeters(User *a_1)
{
	printf("Enter centimeters to be converted to inches: ");
	scanf("%lf", &(*a_1).centimeters);
	printf("INPUT: %f centimeters \n", a_1->centimeters);
}

void convertInchesToCentimeters(User *a_1)
{
	printf("Converting %f Inches to Centimeters...\n\n", a_1->inches);
	a_1->inches *= (1 / 0.393701);
	printf("CONVERSION: %f CENTIMETERS\n\n", a_1->inches);
}

void convertCentimetersToInches(User *a_1)
{
	printf("Converting %f Centimeters to Inches...\n\n", a_1->centimeters);
	a_1->centimeters *= (1 / 2.54);
	printf("CONVERSION: %f INCHES\n\n", a_1->centimeters);
}
