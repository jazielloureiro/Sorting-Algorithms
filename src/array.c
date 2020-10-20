#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 100

void fill_array(int *array){
	int i;

	srand((unsigned int) time(NULL));
	
	for(i = 0; i < SIZE_ARRAY; i++)
		array[i] = rand() % MAX_RAND;
}

void print_array(char *name, int *array){
	int i;
	
	printf("%s = {", name);
	
	for(i = 0; i < SIZE_ARRAY; i++)
		printf("%d, ", array[i]);
		
	printf("\b\b}\n");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
