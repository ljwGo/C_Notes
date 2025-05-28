#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int a;
	int count = 0;
	int *pa = NULL;
	
	while (1){
		printf("please input a number:(if input -1 end)");
		scanf("%d",&a);
		
		if (a == -1){
			for (int i = 0; i<count; i++){
				printf("%d\n",pa[i]);
			}
			free(pa);
			break;
		}
		
		count++;
		// realloc
		pa = (int *)realloc(pa,count * sizeof(int));
		pa[count - 1] = a;
	}
	return 0;
}