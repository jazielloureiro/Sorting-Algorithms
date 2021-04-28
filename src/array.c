#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array.h"

void fill_array(int *array){
	const int MAX_RAND = 100;

	srand((unsigned int) time(NULL));
	
	for(int i = 0; i < SIZE_ARRAY; i++)
		array[i] = rand() % MAX_RAND;
}

void print_array(char *name, int *array){
	printf("%s = {", name);
	
	for(int i = 0; i < SIZE_ARRAY; i++)
		printf("%d, ", array[i]);
		
	printf("\b\b}\n");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
