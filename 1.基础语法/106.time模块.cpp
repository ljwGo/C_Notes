#include <stdio.h>
#include <time.h>

int main(void){
	
	struct tm *time1;
	time_t t;
	time(&t); // t的地址上存放时间戳
	
	printf("t:%lld\n", t);
	time1 = localtime(&t); // 获取结构时间
	
	printf("tm_sec:%d\n", time1->tm_sec); // 
	printf("tm_min:%d\n", time1->tm_min); //
	printf("tm_hour:%d\n", time1->tm_hour); //
	printf("tm_mday:%d\n", time1->tm_mday); //
	printf("tm_mon:%d\n", time1->tm_mon); //
	printf("tm_year:%d\n", time1->tm_year); //
	printf("tm_wday:%d\n", time1->tm_wday); //
	printf("tm_yday:%d\n", time1->tm_yday); //
	printf("tm_isdst:%d\n", time1->tm_isdst); //
	
	return 0;
}