#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Gate{
	int type;
	struct Gate* left;
	struct Gate* right;
}Gate;


void setGateType(Gate *g, int gateVal);
int returnType(Gate* g);

int main(int argc, char**argv){
	Gate *p = malloc(sizeof(Gate));
	assert(p != NULL);
	int gateValue = 10;
	setGateType(p, gateValue);
	returnType(p);
	free(p);

	return 0;
}

int returnType(Gate* g){
	printf("Type: %i \n", g->type);
}

void setGateType(Gate *g, int gateVal){
	g->type = gateVal;
}
