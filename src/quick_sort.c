#include "array.h"

int partition(int *array, int start, int end){
	int i, pivot;
	
	for(i = start, pivot = end - 1; i < pivot; i++)
		if(array[i] < array[pivot])
			swap(&array[i], &array[start++]);

	swap(&array[pivot], &array[start]);
	
	return start;
}

void quick_sort(int *array, int start, int end){
	if(start < end){
		int partition_index = partition(array, start, end);
	
		quick_sort(array, start, partition_index);
		quick_sort(array, partition_index + 1, end);
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	quick_sort(array, 0, SIZE_ARRAY);
	
	print_array("Sorted array", array);

	return 0;
}
