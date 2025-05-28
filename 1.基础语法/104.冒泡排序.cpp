#include <stdio.h>

void bubble_sort(int [], int);

void bubble_sort(int array[], int end_index){
	if (0 == end_index){
		return;
	}
	
	int i = 0, j = 1;
	int temp;
	while (j <= end_index){
		if (array[i] > array[j]){
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		i++;
		j++;
	}
	bubble_sort(array, i-1);
}

int main(void){
	
	
	
	
	return 0;
}