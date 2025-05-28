#include <stdio.h>

int main(){
	char *phrase[] = {
		"hello world",
		"you can you up no can no bb",
		"can can can can?",
		"never give up"
	};
	
	int i;
	
	for (i=0; i<4; i++){
		printf("%s\n",phrase[i]);
	}
	
	return 0;
}