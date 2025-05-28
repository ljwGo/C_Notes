#include <stdio.h>

int main(){
    char *phrase[] = {
        "hello world",
        "you can you up no can no bb",
        "can can can can?",
        "never give up"
    };
    
	char **my_phrase = &phrase[2];
	
	char **other_phrase[3];
	
	other_phrase[0] = &phrase[0];
	other_phrase[1] = &phrase[1];
	other_phrase[2] = &phrase[3];
	
    return 0;
}