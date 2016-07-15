#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int n, int m){
	if(n == m){	
		return n;
	}
	else if(n > m){
	/*	printf("gcd(%d -= %d), %d) STORED ON STACK\n", n, m, m); */
		gcd((n -= m), m);
	/*	printf("gcd(%d -= %d), %d) RELEASE FROM STACK\n", n, m, m); */
	}else if(m < n){
	/*	printf("gcd(%d -= %d), %d) STORED ON STACK\n", n, m, n); */
		gcd(n, (m -= n));
	/*	printf("gcd(%d -= %d), %d) RELEASED FROM STACK\n", n, m, n); */
	}
}

void printInt(int n){
	/* assert(n > 0); */
	if(n > 9){
		printInt(n / 10);
	printf("%d\n", (n % 10));
	}
}

void solveHanoi(int n, char a, char b, char c){
	if(n == 1){
		printf("DEBUG: conditional: if(n == 1): satisified: move disk from pole %c to pole %c\n", a, b);
	}else{
		printf("DEBUG: conditional: else (%d != 1): satisfied: calling solveHanoi(%d - 1, %c, %c, %c)\n", n, n, a, c, b);
		solveHanoi(n - 1, a, c, b);
		printf("Debug: conditional: else (%d != 1): satisfied: move disk from pole %c to pole %c\n", n, a, b);
		printf("DEBUG: calling solveHanoi(%d - 1, %c, %c, %c)\n", n, c, b, a);
		solveHanoi(n - 1, c, b, a);
	}
}

void selectionSort(double array[], int n){
	srand(time(NULL));
	for(int x = 0; x < n; x++){
		array[x] = (rand() % 1000 + 1);
	}
	for(int i = 0; i < n; i++){
		int indexLargest = i;
		/* invariant: indexLargest is the index of the largest element in the range 0 .. 0 */
		for(int j = i; j < n; j++){
			/* invariant: indexLargest is the index of the largest element in the range 0 .. (j - 1) */
			if(array[j] > array[indexLargest]){
				indexLargest = j;
			}
			/* invariant: indexLargest is the index of the largest element in the range 0 .. j */
		}
		/* invariant: indexLargest is the index of the largest element in the range 0 .. (array.length - 1) */		
		int temp = array[i];
		array[i] = array[indexLargest];
		array[indexLargest] = temp;
	}
	for(int y = 0; y < n; y++){
		printf("ELEMENT %d: %f\n", (y + 1), array[y]);
	}
}	

void printBinary(int i){
	if(i == 0 || i == 1){
		printf("Base Case: i == 0 || i == 1: %d\n", i);
	}else{
		printf("printBinary(%d / 2) STORED ON STACK\n", i);
		printBinary(i / 2);	
		printf("printBinary(%d / 2) RELEASE FROM STACK\n", i);
		printf("%d modulus 2 = %d\n\n", i, (i % 2));
	}
}

void insertionSort(double array[], int n){
	srand(time(NULL));
	for(int x = 0; x < n; x++){
		array[x] = (rand() % 1000 + 1);
	}
	for(int i = 1; i < n; i++){
		int j = i;
		while(j > 0 && array[j] < array[j - 1]){
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
	for(int y = 0; y < n; y++){
		printf("ELEMENT %d: %f\n", (y + 1), array[y]);
	}	
}

void shellSort(double array[], int n){
	srand(time(NULL));
	for(int x = 0; x < n; x++){
		array[x] = (rand() % 1000 + 1);
	}
	
}	

void mergeSort(double array_1[], double array_2[], double array_3[], int n){
	printf("MERGE SORT IN PROCESS\n\n");
        srand(time(NULL));
        for(int x = 0; x < n; x++){
                array_1[x] = (rand() % 1000 + 1);
        }
	insertionSort(array_1, n);
	FILE *ptr_file_1;
	ptr_file_1 = fopen("unsorted_array_1.txt", "w+");
	for(int j = 0; j < n; j++){
		fprintf(ptr_file_1, "%f ", array_1[j]);
	}
	srand(time(NULL));
        for(int y = 0; y < n; y++){
                array_2[y] = (rand() % 1000 + 1);
        }
	insertionSort(array_2, n);
	FILE *ptr_file_2;
	ptr_file_2 = fopen("unsorted_array_2.txt", "w+");
	for(int k = 0; k < n; k++){
		fprintf(ptr_file_2, "%f  ", array_2[k]);
	}

	FILE *ptr_file_3;
	ptr_file_3 = fopen("mergeSorted_array_3.txt", "w+");

	double file_1_sortedDouble;
	double file_2_sortedDouble;
	fscanf(ptr_file_1, "%d", &file_1_sortedDouble);
	fscanf(ptr_file_2, "%d", &file_2_sortedDouble);
	while(!ptr_file_1.ferror() && !ptr_file_2.ferror())
	{
		if(file_1_sortedDouble > file_2_sortedDouble)
		{
			fprintf(ptr_file_3, "%d ", file_2_sortedDouble);
			fscanf(ptr_file_2, "%d", &file_2_sortedDouble);
		}
		else if(file_1_sortedDouble < file_2_sortedDouble)
		{
			fprintf(ptr_file_3, "%d ", file_1_sortedDouble);
			fscanf(ptr_file_1, "%d", &file_1_sortedDouble);
		}
		else if(file_1_sortedDouble == file_2_sortedDouble)
		{
			fprintf(ptr_file_3, "%d ", file_1_sortedDouble);
			fprintf(ptr_file_3, "%d ", file_2_sortedDouble);

			fscanf(ptr_file_1, "%d", &file_1_sortedDouble);
			fscanf(ptr_file_2, "%d", &file_2_sortedDouble);
		}
	
		if(ptr_file_1.ferror() && !ptr_file_2.ferror())
		{
			fprintf(ptr_file_3, "%d ", file_1_sortedDouble);
		}

		if(!ptr_file_1.ferror() && !ptr_file_3.ferror())
		{
			fprintf(ptr_file_3, "%f ", file_2_sortedDouble);
		}
	}

	fclose(ptr_file_1);
	fclose(ptr_file_2);
	fclose(ptr_file_3);
}

int main()
{
	int x = 0;
	int y = 0;
	
	printf("ENTER INTEGER 1: ");
	scanf("%d", &x);
	printf("ENTER INTEGER 2: ");
	scanf("%d", &y);
	
	printf("GREATEST COMMON DIVISOR: %d\n\n", gcd(x , y));

	int userInt, userHanoi;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	printf("ENTER INT (printInt()): ");
	scanf("%d", &userInt);
	printInt(userInt);
	printf("ENTER INT (solveHanoi()): ");
	scanf("%d", &userHanoi);
	solveHanoi(userHanoi, a, b, c);
	
	int n;
	printf("ENTER # ARRAY ELEMENTS (SELECTION SORT): ");
	scanf("%d", &n);
	double *array = malloc(n * sizeof(double));
	selectionSort(array, n);
	
	printf("\n\n\n");

	int i;
	printf("ENTER INTEGER TO CONVERT TO BINARY: ");
	scanf("%d", &i);
	printBinary(i);
	
	printf("\n\n\n");

        int z;
        printf("ENTER # ARRAY ELEMENTS (INSERTION SORT): ");
        scanf("%d", &z);
        double *array_1 = malloc(n * sizeof(double));
        insertionSort(array_1, z);

	printf("\n\n\n");

	return 0;
}

