#include <stdio.h>

int main(){
	char choice;
	char second;
	
	printf("please input a choice:");
	scanf("%c",&choice);
	
	switch(choice){
		case 'A':printf("score between 90 and 100\n");
		case 'B':printf("score between 80 and 89\n");
		case 'C':printf("score between 70 and 79\n");
		case 'D':printf("score between 60 and 69\n");
		case 'E':printf("you failed to exam!\n");
		default : printf("don not proud\n");
	}
	
	getchar(); // 拿取标准输入流中一个字符，本次拿的是回车键

	printf("please input a choice again:");
	scanf("%c",&second);

	switch(second){
		case 'A':printf("score between 90 and 100\n");break;
		case 'B':printf("score between 80 and 89\n");break;
		case 'C':printf("score between 70 and 79\n");break;
		case 'D':printf("score between 60 and 69\n");break;
		case 'E':printf("you failed to exam!\n");break;
		default : printf("don not proud\n");
	}
}