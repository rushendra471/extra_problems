/* Given two integers X, Y, write a function for X*Y without using multiplication or addition operators. Use bit operators*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int getMultiply(int, int);
main(){
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	printf("%d", getMultiply(num1, num2));
	fflush(stdin);
	getchar();
}

int getMultiply(int n1, int n2){
	int r=0;
	if (n1 < 0 && n2<0){
		n1 = ~(n1 - 1);
		n2 = ~(n2 - 1);
	}
	else if (n2<0){
		r = n1;
		n1 = n2;
		n2 = r;
	}
	r = 0;
	while (n2 > 0){
		if (n2 & 1)
			r += n1;
		n1 = n1 << 1;
		n2 = n2 >> 1;
	}
	return r;
}