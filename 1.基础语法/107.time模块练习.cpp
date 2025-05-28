#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	struct tm *ptm;
	time_t t;
	time(&t);
	
	ptm = localtime(&t);
	
	FILE *fp;
	
	if ((fp = fopen("hello.txt", "w")) == NULL){
		printf("open the file error!\n");
		exit(EXIT_FAILURE);
	}
	
	fprintf(fp, "%d-%d-%d", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday);
	
	fclose(fp);
	
	if ((fp = fopen("hello.txt", "r")) == NULL){
		printf("open the file error!\n");
		exit(EXIT_FAILURE);
	}
	
	int year, month, day;
	fscanf(fp, "%d-%d-%d", &year, &month, &day);
	
	fclose(fp);
	fp = NULL;
	
	printf("year:%d, month:%d, day:%d\n", year, month, day);
	
	return 0;
}