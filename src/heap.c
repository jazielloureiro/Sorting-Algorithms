#include "array.h"

void heap_sort(int *array){
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	heap_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
