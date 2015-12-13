/* Given three unsigned numbers as input X, Y, Z find out X to the power of Y modulo Z (power(x,y) mod z)*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int getAns(int, int, int);
int main(){
	int x, y, a;
	scanf("%d%d%d",&x,&y,&a);
	printf("%d\n", getAns(x, y, a));
	fflush(stdin);
	getchar();
	return 0;
}
int getAns(int x,int y,int a){
	int res=1;
	x=x%a;
	while(y>0){
		if(y%2)
			res*=x;
		x=(x*x)%a;
		y/=2;
	}
	return (res%a);
}