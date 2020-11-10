#include "array.h"
#include <stdbool.h>

void odd_even_sort(int *array){
	bool swapped = true;
	
	while(swapped){
		int i;
		swapped = false;

		for(i = 1; i < SIZE_ARRAY - 1; i += 2){
			if(array[i] > array[i + 1]){
				swap(&array[i], &array[i + 1]);
				swapped = true;
			}
		}

		for(i = 0; i < SIZE_ARRAY - 1; i += 2){
			if(array[i] > array[i + 1]){
				swap(&array[i], &array[i + 1]);
				swapped = true;
			}
		}
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	odd_even_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
