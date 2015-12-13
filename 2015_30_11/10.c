#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define L 256
main(){
	FILE *fp1 = fopen("sam.txt", "r");
	FILE *fp2 = fopen("sam.txt", "r");
	char line[L];
	int cnt = 0,k;
	printf("Enter no.of lines to read from last:-");
	scanf("%d", &k);
	while (fgets(line, L, fp1) != NULL){
		if (cnt < k)
			cnt++;
		else
			fgets(line, L, fp2);
	}

	if (cnt < k) {
		printf("less than 10 lines in the file\n");
		return 1;
	}

	while (fgets(line, L, fp2) != NULL)
		printf("%s", line);
	
	fclose(fp1);
	fclose(fp2);
	fflush(stdin);
	getchar();
}
