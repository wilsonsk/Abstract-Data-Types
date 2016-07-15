#include <stdlib.h>
#include <stdio.h>

#define TYPE void*

struct Node{
	int val;
};

double printThis(TYPE);

int main(){
	TYPE nd_1 = 0;
	printf("This dereferenced void pointer: %f\n\n",printThis(nd_1));

return 0;
}

double printThis(TYPE nd){
	struct Node* newNd = (struct Node*)malloc(sizeof(struct Node));
	nd = newNd;
	return *((double*)nd->val); 
}

void myFunction(int(*ptr_function)(TYPE)){

}
