#include <stdio.h>
#include <math.h>

int main(void){
	int result, end, j, sum, count;
	char isView;
	int start = 1, num = 1;

	printf("please input a number:");
	scanf("%d",&count);
	
	int repeat_array[count-2][5]; //子数组数据对应 ——打印式子开始值，打印式子结束值，式子的个数, 式子的结果, 立方运算使用的数字
	
	for (int i=3; i<=count; i++){
		
		result = pow(i,3);
		
		while(1){
			j = start;
			sum = start;
			while (sum <= result){
				if (sum == result){
					repeat_array[i-3][0]=start;
					repeat_array[i-3][1]=end;
					repeat_array[i-3][2]=num;
					repeat_array[i-3][3]=result;
					//goto PHRASE;
					goto Two_Over;
				}
				j += 2;
				sum += j;
				num++;
			}
			start += 2;
			num = 1;
		}
		
		// goto跳出两层循环(程序附加条件前的代码)
		/*PHRASE: if (num < 4) { //根据式子个数打印
					printf("%d + %d + %d =  %d\n", start, start+2, end, result);
				}
				else{
					printf("%d + %d + ... + %d = %d\n", start, start+2, end, result);
				}*/
				
		Two_Over :{ //为了跳出两层循环
			;
		}
	}
	printf("tell me if need to show the phrase(y/n):");
	getchar();
	scanf("%c",isView);
	
	if ('y' == isView){
		for (int i=0; i<=count-3; i++){
			if(repeat_array[i][2] < 4){
				printf("%d^3 == %d == %d + %d + %d\n",repeat_array[i][4], repeat_array[i][3], repeat_array[i][0], repeat_array[i][0]+2, repeat_array[i][1]);
			}
			else{
				printf("%d^3 == %d == %d + %d + ... + %d\n",repeat_array[i][4], repeat_array[i][3], repeat_array[i][0], repeat_array[i][0]+2, repeat_array[i][1]);
			}
		}
	}
	
	return 0;
}