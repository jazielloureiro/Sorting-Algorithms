#include "array.h"
#include <stdbool.h>

void cocktail_sort(int *array){
	int start, end;
	bool swapped;
	
	for(start = 0, end = SIZE_ARRAY - 1, swapped = true;
	    swapped && start < end;
	    start++, end--){
	    	int i;
		swapped = false;

		for(i = start; i < end; i++){
			if(array[i] > array[i + 1]){
				swap(&array[i], &array[i + 1]);
				swapped = true;
			}
		}

		if(!swapped)
			break;

		for(i = end - 1; i > start; i--){
			if(array[i] < array[i - 1]){
				swap(&array[i], &array[i - 1]);
				swapped = true;
			}
		}
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	cocktail_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
