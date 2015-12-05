#include <stdio.h>

int main(){
	int count = 0;
	char * fileName = "sam.txt";
	FILE * fpIn;
	if ((fpIn = fopen(fileName, "r")) == NULL)
		printf(" file %s open error\n", fileName);
	fseek(fpIn, 0, SEEK_END);
	while (count < 10){
		fseek(fpIn, -2, SEEK_CUR);
		if (ftell(fpIn)<0L)
			break;
		char now = fgetc(fpIn);
		printf("%c", now);
		if (now == '\n')
			++count;
	}
	fclose(fpIn);
}