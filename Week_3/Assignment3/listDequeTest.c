#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque(); 
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("%g\n", frontCirListDeque(q));
	printf("%g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);
/* 	printf("%g\n", frontCirListDeque(q));	*/
	removeBackCirListDeque(q);
/*	printf("%g\n", backCirListDeque(q));	*/
	printCirListDeque(q);
	reverseCirListDeque(q);
	printCirListDeque(q);
/*	freeCirListDeque(q);	*/
	return 0;
}

