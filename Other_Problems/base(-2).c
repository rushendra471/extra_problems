/* Decimal to base -2 converter */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
void getConvert(int, int[]);
main(){
	int n,arr[16];
	scanf("%d", &n);
	getConvert(n,arr);
	for (n = 0; n < 16; n++)
		printf("%d", arr[n]);
	fflush(stdin);
	getchar();
}

void getConvert(int n,int a[]){
	int i=15;
	while (1){
		a[i] = n % (-2);
		if (n == 0){
			if (a[i] == -1){
				a[i] = 1;
				n++;
			}
			break;
		}
		n /= (-2);
		if (a[i] == -1){
			a[i] = 1;
			n++;
		}
		i--;
	}
	for (n = i; n >= 0; n--)
		a[n] = 0;
}