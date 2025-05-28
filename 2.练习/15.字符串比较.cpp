#include <stdio.h>
#include <string.h>

int similar(char *p, char *c){
	int x, y, i, j;
	x = strlen(p) + 1;
	y = strlen(c) + 1;
	int a[x][y] = {0};
	
	for (i=0; i<x; i++){
		for (j=0; j<y; j++){
			a[i][j] = 0;
			printf("%d,", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for (i = 0; i<x-1; i++){
		for (j = 0; j<y-1; j++){
			if (*(p+i) == *(c+j)){
				a[i+1][j+1] = a[i][j] + 1;
			}
			else{
				if (a[i+1][j] > a[i][j+1]){
					a[i+1][j+1] = a[i+1][j];
				}
				else{
					a[i+1][j+1] = a[i][j+1];
				}
			}
		}
	}

	for (i=0; i<x; i++){
		for (j=0; j<y; j++){
			printf("%d,", a[i][j]);
		}
		printf("\n");
	}

	i = x-1;
	j = y-1;
	while(a[i][j] != 0){
		if (a[i][j] == a[i][j-1]){
			j-=1;
		}
		else if (a[i][j] == a[i-1][j]){
			i-=1;
		}
		else{
			printf("%c", *(p+i-1));
			i-=1;
			j-=1;
		}
	}
	return 222;
}

int main(void){
//	char a[] = "hello world";
//	char *p = a;
//	printf("%d, %d\n", sizeof(a), strlen(a));
//	printf("%d, %d\n", sizeof(p), strlen(p));

	char a[] = "aefaega";
	char b[] = "aegsdgg";
	similar(a, b);
	return 0;
}