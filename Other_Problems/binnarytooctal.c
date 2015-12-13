/* Binary to octal converter */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
int getConvert(int);
int main()
{
	int n;
	printf("Enter binary number ");
	scanf("%d", &n);
	n = getConvert(n);
	if (n == -1)
		printf("Invalid Binary Number");
	else
		printf("%o", n);
	fflush(stdin);
	getchar();
	return 0;
}

int getConvert(int n){
	int t=0, i=1, temp,res=0;
	while (n != 0 && t == 0)
	{
		temp = n % 10;
		res += temp*i;
		i *= 2;
		n /= 10;
		if (temp != 0 && temp != 1)
			t = 1;
	}
	if (t == 1)
		return -1;
	else
		return res;
}

