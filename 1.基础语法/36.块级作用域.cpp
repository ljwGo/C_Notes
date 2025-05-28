#include <stdio.h>

int main(){
	int i = 10;
	{
		int i = 20;
		{
			int i = 30;
			printf("i1:%d\n",i);
		}
		
		{
			int i = 40;
			printf("i2:%d\n",i);
		}
		
		printf("i3:%d\n",i);
		
	}
	printf("i4:%d\n",i);
	
	return 0;
}