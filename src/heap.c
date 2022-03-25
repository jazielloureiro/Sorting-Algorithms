#include "array.h"

void sift_down(int *array, int i, int n) {
	int j = i * 2 + 1;

	if(j < n) {
		if(j + 1 < n)
			if(array[j + 1] > array[j])
				j++;
		if(array[i] < array[j]) {
			swap(&array[i], &array[j]);
			sift_down(array, j, n);
		}
	}
}

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
