#include "array.h"

void bubble_sort(int *array){
	int max = SIZE_ARRAY - 1, i, j;
	
	for(i = 0; i < max; i++)
		for(j = 0; j < max - i; j++)
			if(array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	bubble_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
