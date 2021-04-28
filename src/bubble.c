#include "array.h"

void bubble_sort(int *array){
	const int MAX = SIZE_ARRAY - 1;
	
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX - i; j++)
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
