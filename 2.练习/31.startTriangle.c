#include <stdio.h>

int main(void){
	
	char * star_array[5] = {
		"    *    \n",
		"   * *   \n",
		"  *   *  \n",
		" *     * \n",
		"* * * * *\n"
	};
	int i;
	
	for (i=0; i<5; i++){
		puts(star_array[i]);
	}
	
	return 0;
}