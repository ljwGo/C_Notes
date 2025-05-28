#include <stdio.h>

int main(){
	int i,j;
	
	int array[6][4];
	
	for (i=0; i<6; i++){
		
		for (j=0; j<6; j++){
			if (4 == j){
				break;
			}
			
			array[i][j] = i*j;
		}
	}
	
	for (i=0; i<6; i++){
		for (j=0; j<4; j++){
			
			printf("%d\n",array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}