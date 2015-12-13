/* getting size of infinite array which has some constraints as if size is n then it has n consecutive 0's number i is choosen as i<i+1 and i+1>i+2 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
int getSize(int[]);
main(){
	int *a,n,i;
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", getSize(a));
	fflush(stdin);
	getchar();
}

int getSize(int a[]){
	int i = 0, j , m;
	while (1){
		if (a[i + 1] > a[i] && a[i + 2] < a[i + 1])
			return i + 1;
		else if (a[i]>a[i+1]){
			if (a[i + 1] == 0)
				return i - 1;
			else
				return i;
		}
		else if (a[i] == 0){
			j = i;
			i /= 2;
			while (i<j){
				m = (i + j) / 2;
				if (a[m + 1]>a[m] && a[m + 2] < a[m + 1])
					return m - 1;
				else if (a[m]>a[m + 1]){
					if (a[m + 1] == 0)
						return m - 1;
					else
						return m;
				}
				else if (a[m] == 0)
					j = m - 1;
				else if (a[m] > a[m + 1] && a[m] < a[m + 1])
					i = m;
			}
		}
		i = (i * 2) + 1;
	}
}