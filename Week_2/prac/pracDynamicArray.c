#include <stdlib.h>
#include <stdio.h>

typedef struct{
	struct Node{
		struct Node* next;
		struct Node* previous;
	};
	struct Node* head;
	struct Node* tail;
	
}DynamicArray;

