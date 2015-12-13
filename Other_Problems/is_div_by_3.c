/*An unsigned number Q is formed by taking input P which is an unsigned integer in string format, K: number of times P repeated to form Q. write a function to find whether the number Q is divisible by 3 or not
ex: Q: 123123123 P: 123 K:3
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
int isDivBy3_1(char *, int);
main(){
	int k;
	char *p;
	p = (char *)malloc(sizeof(char));
	printf("Enter string and number:");
	gets(p);
	scanf("%d", &k);
	k = isDivBy3_1(p, k);
	if (k == 1)
		printf("It is divisible by 3");
	else if (k == 0)
		printf("It is not divisible by 3");
	else
		printf("You entered special characters...");
	fflush(stdin);
	getchar();
}
int isDivBy3_1(char p[], int k){
	int len = 0, cnt = 0;
	while (p[len] != '\0'){
		if (p[len] >= 48 && p[len] < 58)
				cnt = cnt + (p[len] - 48);
		else
			return -1;
		len++;
	}
	if (cnt % 3 == 0)
		return 1;
	else if (k % 3 == 0)
		return 1;
	else
		return 0;
}