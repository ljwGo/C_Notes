#include <stdio.h>

int main(void){
	char *result_a[2] = {"OK", "Speeding"};
	int speed;
	int result = 0;
	scanf("%d", &speed);
	
	if (0 <= speed && speed <= 500){
		if (speed > 60){
			result = 1;
		}
		
		printf("Speed: %d - %s", speed, result_a[result]);
	}
	
	return 0;
}