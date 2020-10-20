#include "array.h"

void merge(int *array1, int size_array1, int *array2, int size_array2){
	int size_array3 = size_array1 + size_array2,
	    array3[size_array3],
	    i = 0, j = 0, k = 0;
	    
	while(i < size_array1 && j < size_array2){
		if(array1[i] < array2[j])
			array3[k++] = array1[i++];
		else
			array3[k++] = array2[j++];
	}
	
	while(i < size_array1)
		array3[k++] = array1[i++];
		
	while(j < size_array2)
		array3[k++] = array2[j++];
		
	for(i = 0; i < size_array3; i++)
		array1[i] = array3[i];
}

void merge_sort(int *array, int start, int end){
	if(end - start > 1){
		int mid = (start + end) / 2;
		
		merge_sort(array, start, mid);
		merge_sort(array, mid, end);
		
		merge(array + start, mid - start, array + mid, end - mid);
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	merge_sort(array, 0, SIZE_ARRAY);
	
	print_array("Sorted array", array);

	return 0;
}
