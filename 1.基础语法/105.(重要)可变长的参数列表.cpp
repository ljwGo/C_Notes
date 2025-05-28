#include <stdio.h>
#include <stdarg.h>

void minprintf(char *, ...);

void minprintf(char *str, ...){
	va_list parg; // 可变长参数使用步骤一:参数列表?
	int i_val;
	double f_val;
	char *pstr, *s_val;
	
	pstr = str;
	
	va_start(parg, str); // 可变长参数使用步骤二, 指明变长参数在哪个具体参数后开始
	for (pstr = str; *pstr; pstr++){
		if (*pstr != '%'){
			putchar(*pstr);
			continue;
		}
		switch (*++pstr){
			case 'd':
				i_val = va_arg(parg, int); // 顺序获取实参, 并且指定类型?
				printf("%d", i_val);
				break;
			case 'f':
				f_val = va_arg(parg, double);
				printf("%f", f_val);
				break;
			case 's':
				for (s_val = va_arg(pang, char *); *s_val; s_val++){
					putchar(*s_val);
				}
				break;
//			case 's':
//				s_val = va_arg(parg, char *);
//				printf("%s", s_val);
//				break;
			default:
				putchar('%');
				putchar(*pstr);
				break;
		}
	}
	
	va_end(parg);
}

int main(void){
	
	minprintf("hello world%f%s%d", 22.2, "hello world", 40);
	
	return 0;
}