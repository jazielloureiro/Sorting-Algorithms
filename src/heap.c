#include "array.h"

void sift_down(int *array, int i, int n){
	int j = i * 2 + 1;

	if(j < n){
		if(j + 1 < n)
			if(array[j + 1] > array[j])
				j++;
		if(array[i] < array[j]){
			swap(&array[i], &array[j]);
			sift_down(array, j, n);
		}
	}
}

void heapify(int *array, int n){
	for(int i = (n - 2) / 2; i >= 0; i--)
		sift_down(array, i, n);
}

void heap_sort(int *array, int n){
	heapify(array, n);

	while(n > 0){
		n--;
		swap(&array[0], &array[n]);
		sift_down(array, 0, n);
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	heap_sort(array, SIZE_ARRAY);
	
	print_array("Sorted array", array);

	return 0;
}
