/* Given a unsigned number as a string input (it can be of length, max 10000 chars) write a function to find whether the number is divisible by 11 or not*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
int isDivBy11(char *);
main(){
	char *num;
	num = (char*)malloc(sizeof(char));
	printf("Enter Number:-");
	gets(num);
	if (isDivBy11(num))
		printf("Number is divisible by 11");
	else
		printf("Number is not divisible by 11");
	fflush(stdin);
	getchar();
}

int isDivBy11(char n[]){
	int i = 0, cnt = 0;
	while(n[i] != '\0'){
		if (i % 2 == 0)
			cnt -= (n[i] - 48);
		else
			cnt += (n[i] - 48);
		i++;
	}
	if (cnt == 0)
		return 1;
	return 0;
}