#include "array.h"

void insertion_sortH(int *array, int h){
	for(int i = h; i < SIZE_ARRAY; i += h){
		for(int j = i; j - h >= 0; j -= h){
			if(array[j] < array[j - h])
				swap(&array[j], &array[j - h]);
			else
				break;
		}
	}
}

void shell_sort(int *array){
	int h;

	for(h = 1; h < SIZE_ARRAY; h = 3 * h - 1);

	do{
		h /= 3;
		insertion_sortH(array, h);
	}while(h != 1);
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	shell_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
