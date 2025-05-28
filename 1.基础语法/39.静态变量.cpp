#include <stdio.h>

void add(void);

void add(void){
	
	static int count = 0;
	
	printf("%d\n",count);
	
	count++;
}

int main(void){
	
	for(int i=0; i<10; i++){
		add();
	}
	
	return 0;
}