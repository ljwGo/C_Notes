#include <stdio.h>

int main(void){
	
	struct Class{
		char name[32];
		unsigned short number;
		unsigned int student_num; 
	};
	
	typedef struct Class To_Class;
	
	return 0;
}