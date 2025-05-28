#include <stdio.h>

int main(){
	
	int array[][4] = {
		(0,1,2,3),
		(4,5,6,7),
		(8,9,10,11),
	};
	
	int i,j;
	
	// b
	for (i=0; i<3; i++){
		for (j=0; j<4; j++){
			printf("%d\n",array[i][j]);
		}
	}
	
	return 0;
}