#include <stdio.h>

int main(){
	int array[10];
	int i;
	
	for (i = 0; i < 10; i++){
		if (4 == i){
			continue; // 
		}
		array[i] = i;
	}
	
	for (i = 0; i < 10; i++){
		printf("%d\n",array[i]);
	}
	
	return 0;
}