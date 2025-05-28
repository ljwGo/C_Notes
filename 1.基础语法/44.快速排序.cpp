#include <stdio.h>

void array_sort(int array[], int, int);

void array_sort(int array[], int start, int end){
	if(start == end){
		return;
	}
	
	int i,j,temp,center;
	
	i = start;
	j = end;
	
	center = array[(start+end) / 2];
	
	do{
		while(array[i] < center){
			i++;
			}
		while(array[j] > center){
			j--;
		}
		
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
		if (i > end){
			i = end;
		}
		if (j < start){
			j = end;
		}
		
	}while(i <= j);
	
	array_sort(array, start, j);
	array_sort(array, i, end);
}

int main(void){
	int array[] = {1, 22, 35, 76, 23, 647, 1341, 135, 423, 52};
	int length = sizeof(array) / sizeof(array[0]);
	int end = length - 1;
	array_sort(array, 0, end);
	for(int i = 0; i < length; i++){
		printf("%d  ",array[i]);
	}
	return 0;
}