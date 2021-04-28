#include "array.h"

void selection_sort(int *array){
	int i;
	
	for(i = 0; i < SIZE_ARRAY - 1; i++){
		int j, min;
		
		for(j = i + 1, min = i; j < SIZE_ARRAY; j++)
			if(array[min] > array[j])
				min = j;
				
		if(min != i)
			swap(&array[i], &array[min]);
	}
}

int main(){
	int array[SIZE_ARRAY];

	fill_array(array);
	
	print_array("Unsorted array", array);
	
	selection_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
