#include <stdio.h>
#include <stdlib.h>

void wordPyramid(int);

void wordPyramid(int layer){
	static const char word[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	// printf("\tA\t");\t 是一个tab键？
	int perLineLen, perLineWord = 0, perLineSpace;
	int i,j,k;
	
	perLineLen = layer * 2 - 1;
	
	for (i = 0; i < layer; i++){
		perLineWord = i * 2 + 1;
		perLineSpace = perLineLen - perLineWord;
		for (j = 0; j < perLineSpace / 2; j++){
			printf(" ");
		}
		
		for (k = 0; k < (perLineWord - 1) / 2; k++){
			printf("%c", word[k]);
		}
		
		printf("%c", word[i]);
		
		for (k = (perLineWord - 1) / 2 - 1; k >= 0; k--){
			printf("%c", word[k]);
		}
		
		for (j = 0; j < perLineSpace / 2; j++){
			printf(" ");
		}
		
		putchar('\n');
	
	}
}

int main(void){

	int layer;
	printf("please input the high of layer is:");
	scanf("%d", &layer);

	if (0 <= layer && layer <= 26){
		wordPyramid(layer);
	}
	else{
		printf("please input a correct number!\n");
	}
	return 0;
}