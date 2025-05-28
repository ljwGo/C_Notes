#include <stdio.h>
#include <time.h>

typedef int (*func)(int *, int);

int time_dec(func, int *, int);
int iron_cut_rec(int *p, int n);
int iron_cut_rec2(int *p, int n);
int iron_cut_no_rec(int *p, int n);

int time_dec(func f, int *p, int n){
	time_t t1, t2;
	t1 = time(NULL);
	int res = (*f)(p, n);
	t2 = time(NULL);
	printf("%.8f\n", t2-t1);
	return res;
}
int iron_cut_rec(int *p, int n){
	int res1 = *(p+n);
	for (int i=1; i<n; i++){
		int res = iron_cut_rec(p, n-i)+iron_cut_rec(p, i);
		if (res > res1){
			res1 = res;
		}
	}
	return res1;
}
int iron_cut_rec2(int *p, int n){
	int max = *(p+n);
	for (int i=1; i<n; i++){
		int res = *(p+i) + iron_cut_rec2(p, n-i);
		if (max < res){
			max = res;
		}
	}
	return max;
}
int iron_cut_no_rec(int *p, int n){
	int res[n+1] = {0};
	for (int i=1; i<n+1; i++){
		int max = *(p+i);
		for (int j=1; j<i; j++){
			int new_n = res[j] + res[i-j];
			if (max < new_n){
				max = new_n;
			}
		}
			res[i] = max;
	}
	return res[n];
}

int main(void){
	int price_table[11] = {0, 1, 3, 4, 5, 6, 8, 9, 11, 12, 15};
	int m = 0;
	scanf("%d", &m);
	printf("%d \n",time_dec(&iron_cut_rec, price_table, m));
	printf("%d \n",time_dec(&iron_cut_rec2, price_table, m));
	printf("%d \n",time_dec(&iron_cut_no_rec, price_table, m));
	return 0;
}

