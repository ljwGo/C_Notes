#include <stdio.h>

int main(){
	int score_a[10];
	int i;
	int *score;
	
	for (i=0; i<10; i++){
		score_a[i] = i;
	}
	
	score = &score_a[0];
	
	printf("score_a[1]: %d\n", *(score+1));
	printf("socre_a[2]: %d\n", *(score+2)); 
	
	return 0;
}