/* Adder of numbers in string format from right to left in equal lengths */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
char* getAdd(char*, char*);
main(){
	char *n1, *n2;
	n1 = (char*)malloc(sizeof(char));
	n2 = (char*)malloc(sizeof(char));
	gets(n1);
	gets(n2);
	printf("%s", getAdd(n1, n2));
	fflush(stdin);
	getchar();
}

char* getAdd(char s1[], char s2[]){
	int i=0, j=0, t, k;
	while (s1[i] != '\0'){
		t = (s1[i] - 48) + (s2[i] - 48);
		if (t > 9){
			for (k = i - 1; k >= (j - 1); k--)
				s1[k] = '0';
			s1[j] = ((s1[j] - 48) + 1) + 48;
			j = i;
			s1[i] = (t % 10) + 48;
		}
		else if (t == 9){
			s1[i] = t + 48;
		}
		else{
			j = i;
			s1[i] = t + 48;
		}
		i++;
	}
	s1[i] = '\0';
	return s1;
}