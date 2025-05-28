#include <stdio.h>

int OneNum(int row, int column){
	/* 
	使用递归的方式，虽然效率降低不少，但是思路清晰
	就是杨辉三角形中一个数的值等于
	其上一行同一列的数，与上一行同一列数的前一个的和
	递归退出条件：
		每一行的首个数和最后一个数恒为 1
	*/
	if (1==column || row==column){
		return 1;
	}
	else return OneNum(row-1, column) + OneNum(row-1, column-1);
}

int main(void){
	
	int i, j;
	
	for (i=1; i<=10; i++){
		for (j=1; j<=i; j++){
			printf("%4d", OneNum(i, j));
		}
		printf("\n");
	}
	
	return 0;
}