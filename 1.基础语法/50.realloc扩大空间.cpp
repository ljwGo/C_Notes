#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	int count = 0;
	int *pnum = NULL;
	
	while (1){
		printf("please input a number(input -1 end process):");
		scanf("%d",num);

		if (num == -1){
			for (int i = 0; i<count; i++){
				printf("%d\n",pnum[i]);
			}
			break;
		}
		
		count++;
		pnum = (int *)realloc(pnum,count * sizeof(int));
		pnum[count] = num;
	}
}
