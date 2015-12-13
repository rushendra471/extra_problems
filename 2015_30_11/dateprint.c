/* given a date print the date as text, example: 10/1/1992 shoudl be printed as tenth january of nineteen ninety two.*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
char* getDate(int);
char* getYear(int);
char* getMonth(int);
char* strcat1(char*, char*);
char* checkDate(char []);
char* strcat2(char [], char []);
int main(){
	char date[11];
	fflush(stdin);
	fgets(date, 11, stdin);
	printf("%s", checkDate(date));
	fflush(stdin);
	getchar();
	return 0;
}

char* checkDate(char s[]){
	int arr[3]={0},i=0,j=0;
	char *str,*str1;
	str = (char *)malloc(100 * sizeof(char));
	str[0] = '\0';
	str1 = (char *)malloc(100 * sizeof(char));
	str1[0] = '\0';
	while(s[i]!='\n'){
		if(s[i]=='/')
			j++;
		else
			arr[j]=(arr[j]*10)+(s[i]-48);
		i++;
	}
	i=0;
	if (arr[1]>0 && arr[1]<13){
		if (arr[1] == 2){
			if ((arr[2] % 4 == 0) && (arr[0]>0 && arr[0]<30))
				i=1;
			else if ((arr[2] % 4 != 0) && arr[0]>0 && arr[0]<29)	
				i=1;
			else
				return "Date is Invalid";
		}
		else if (arr[1]>7) 
			arr[1]++;
		if ((arr[1] % 2 == 1) && arr[0]>0 && arr[0]<32)
			i=1;
		if (arr[0]>0 && arr[0]<31)
			i=1;
	}
	
	if(i=1){
		strcat2(str,strcat1(getMonth(arr[1]),getYear(arr[2])));
		strcat2(str1,getDate(arr[0]));
		return strcat2(str1,str);
	}
	return "Date is Invalid";
}

char* getDate(int n){
	char *list1[8] = { "twenty", " thirty", " fourty", " fifty", " sixty", " seventy", " eighty", " ninty" };
	char *list2[20] = { " ", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine", " ten", " eleven", " tweleve", " thirteen", " fourteen", " fifteen", " sixteen", " seventeen", " eighteen", " ninteen" };
	if (n<20)
		return (list2[n]);
	return (strcat1(list1[(n / 10) - 2], list2[n%10]));
}   

char* getMonth(int n){
	char *mon[50] = { "january", "febraury", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	return mon[n - 1];
}

char* getYear(int n){
	char *str;
	str = (char *)malloc(1000 * sizeof(char));
	str[0] = '\0';
	strcat2(str, getDate(n/100));
	strcat2(str, "");
	strcat2(str, getDate(n%100));
	return (str);
}

char* strcat1(char s1[], char s2[]){
	char s[1000]="\0";
	int i = 0, j = 0;
	while (s1[i] != '\0')
		s[i++] = s1[i];
	while (s2[j] != '\0')	
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}


char* strcat2(char s1[], char s2[]){
	int i = 0, j = 0;
	while (s1[i] != '\0')	i++;
	while (s2[j] != '\0')	s1[i++] = s2[j++];
	s1[i] = '\0';
	return s1;
}