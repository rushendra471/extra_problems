/* */
#include<stdio.h>
#include<malloc.h>
int* generateNum(int *);
int check(int, int);
void main(){
	int *a, i , cnt=0;
	a = generateNum(&cnt);
	for (i = 0; i<cnt; i++)
		printf("%d\n", a[i]);
	fflush(stdin);
	getchar();
}
int* generateNum(int *cnt){
	int i, *a ;
	a = (int*)malloc(1000 * sizeof(int));
	for (i = 100000; i<500000; i++)
		if (check(i, 2)){
			a[*cnt] = i;
			*cnt = *cnt + 1;
		}
	return a;
}
int check(int n, int m){
	int a[10] = { 0 }, r;
	r = n*m;
	if (r >= 100000 && r<10000000){
		while (n>0){
			a[n % 10]++;
			n /= 10;
		}
		while (r>0){
			n = r % 10;
			a[n]--;
			r /= 10;
			if (a[n]<0)
				return 0;
		}
		return 1;
	}
	return 0;
}
