/* C program to generate permutations*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cnt=0;
char arr[40320][9];
void strcopy(char*, char*);
void swap(char *, char *);
void getSort(char[]);
void permute(char *, int, int);
main()
{
	int i;
	char str[9];
	gets(str);
	getSort(str);
	permute(str, 0, 7);
	for (i = 0; i < 40320; i++)
		printf("%s\n", arr[i]);
	fflush(stdin);
	getchar();
}

void permute(char *a, int l, int r)
{
	int i;
	if (l == r){
		strcopy(arr[cnt++], a);
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i));
		}
	}
}


void getSort(char string[]){
	int i, j;
	char temp;
	for (i = 0; i<7; i++)
	{
		for (j = i + 1; j<8; j++)
		{
			if (string[i] > string[j])
			{
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}
}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void strcopy(char s1[], char s2[]){
	int i = 0;
	while (s2[i]!='\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}