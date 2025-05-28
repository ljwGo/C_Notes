#include <stdio.h>
#include <time.h>

enum Week {sun, mon,tue, wed, thu, fri, sat};

int main(void){
	struct tm *p;
	time_t t;
	time(&t);
	p = localtime(&t);
	
	enum Week today;
	//today = p->tm_wday;
	
	//switch (today){
	switch (p->tm_wday){
		case mon:
		case tue:
		case wed:
		case thu:
		case fri:
				printf("working\n");
				break;
		case sat:
		case sun:
				printf("relax\n");
				break;
		default:
				printf("your are a water fish\n");
	}
	
	return 0;
}