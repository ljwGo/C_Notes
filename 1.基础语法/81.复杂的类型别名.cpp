// typedef int *P_TO_ARRAY1[5]; // int指针数组
typedef int *P_TO_ARRAY1; // int指针类型

//typedef int (*P_TO_ARRAY2)[5]; // int数组指针
typedef int (*P_TO_ARRAY2); // int指针类型

// 可能是错的, 因为c怎么可能声明一个函数类型?
typedef void *P_TO_FUNC1(int, int); // 返回值为void *类型的函数

typedef void (*P_TO_FUNC2)(int, int); // 返回值为void两个int形参的函数指针

int main(void){
	P_TO_ARRAY1 array1[10];  //
	
	/*P_TO_ARRAY2 array2[4];  //
	int array[2][4];
	array2 = array;*/
	
	/*(P_TO_ARRAY2 array2)[4];  //
	int array[2][4];
	array2 = array;*/
	
	return 0;
}