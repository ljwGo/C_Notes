#include <stdio.h>

int func(int, int);

int func(int a, int b){
	int tmp;
	if (a % b == 0){
		return b;
	}
	else{
		tmp = b;
		b = a % b;
		a = tmp;
		return func(a, b);
	}
}

int main(void){
	
	printf("%d", func(16, 12));
	return 0;
}

//#include <stdio.h>
//
//int a;
//int main(void){
//	int b;
//	static int c;
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
