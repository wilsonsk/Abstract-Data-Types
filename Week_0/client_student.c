#include "Student.h"

int c = 8;       /*global var*/

int main(int argc, const char *argv[]){
	struct Student Joe;
	Joe.id = 25;
	strcpy(Joe.name, "Joe");

	printStudent(&Joe);

	return 0;
}
