#include "array.h"

void counting_sort(int *array){
	int max = array[0];
	
	for(int i = 1; i < SIZE_ARRAY; i++)
		if(max < array[i])
			max = array[i];
			
	int array_aux[max + 1];
	
	for(int i = 0; i <= max; i++)
		array_aux[i] = 0;
		
	for(int i = 0; i < SIZE_ARRAY; i++)
		array_aux[array[i]]++;
		
	for(int i = 0, j = 0; i <= max; i++){
		while(array_aux[i] != 0){
			array[j++] = i;
			array_aux[i]--;
		}
	}
}

int main(){
	int array[SIZE_ARRAY];
	
	fill_array(array);
	
	print_array("Unsorted array", array);
	
	counting_sort(array);
	
	print_array("Sorted array", array);

	return 0;
}
