#include <stdio.h>

int main(void){
	
	int hours, minutes;
	char morning[] = "AM";
	char afternoon[] = "PM";
	char *now = morning;
	
	scanf("%d:%d", &hours, &minutes);
	if (0<=hours && hours<24 && 0<=minutes && minutes<60){
		if (12 < hours){
			hours -= 12;
			now = afternoon;
		}
		else if (hours == 12){
			now = afternoon;
		}
		printf("%d:%d %s", hours, minutes, now);
	}
	
	return 0;
}