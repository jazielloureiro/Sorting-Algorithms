#include "array.h"

void insertion_sort(int *array){
	for(int i = 0; i < SIZE_ARRAY; i++){
		for(int j = i; j > 0; j--){
			if(array[j] < array[j - 1])
				swap(&array[j], &array[j - 1]);
			else
				break;
		}
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	insertion_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
