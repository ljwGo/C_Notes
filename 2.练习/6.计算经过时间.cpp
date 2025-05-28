#include <stdio.h>

int main(void){
	int current_time = 0, pass_minutes = 0;
	int hours = 0, minutes = 0;
	int after_time;
	scanf("%d %d", &current_time, &pass_minutes);
	
	
	if (0 <= current_time && current_time < 2400){  // 输入的时间是一天内的有效时间
		// printf("%d", current_time); 当输入012时，current_time的值是12，也就是说前面的0被处理了
		minutes = current_time % 100;  // 取到当前时间的分钟数
        if (0 <= minutes && minutes < 60){
            current_time = current_time / 100 * 100;  // 去掉当前时间的分钟数，保留小时数

            minutes += pass_minutes;
            hours = minutes / 60;
            minutes %= 60;

            if (minutes < 0){
                hours+=1;
                minutes += 60;
            }

            after_time = current_time + hours*100 + minutes;

            if (0 <= after_time && after_time < 2400){
                if (after_time < 60){
                    printf("0%d\n", after_time);
                }
                else{
                    printf("%d\n", after_time);
                }
            }
            else{
                printf("超出一天内的时间了!");
            }
            
        }
        else{
            printf("输入的分钟数不能超过60");
        }
	}
	return 0;
}