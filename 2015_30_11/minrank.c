/* Min Rank of a given number: Given an unsigned number as input, find the index of the number (index starts from 0) in all permutations of the number, sorted in ascending order. input 213: output 2 (as 123, 132, 213, 231, 312, 321 are the permutations and 2 is the index values of 213)*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int getMinRank(int);
int fact(int);
int power(int,int);
main(){
	int num;
	scanf("%d", &num);
	printf("%d", getMinRank(num)-1);
	fflush(stdin);
	getchar();
}
int getMinRank(int n){
	int i,t=n,len=0,fn,pos=0;
	while (t > 0){
		fn = t;
		t /= 10;
		len++;
	}
	if (len == 1)
		return 1;
	t = n;
	while (t > 0){
		if (fn > (t%10))
			pos++;
		t /= 10;
	}
	t = fact(len - 1);
	n = n % power(10, len - 1);
	return ((pos*t)+getMinRank(n));
}

int fact(int n){
	int i,f=1;
	for (i = 1; i <= n; i++)
		f *= i;
	return f;
}

int power(int b, int p){
	int i,pow=1;
	for (i = 0; i < p; i++)
		pow *= b;
	return pow;
}