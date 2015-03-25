#include <stdio.h>

int main(int argc, const char *argv[])
{
	char s[20];
	scanf("%s", s);

	FILE* fp;

	fp = fopen(s, "r");

	if (fp == NULL)
	{
		printf("\anot exist!\n");
	} 
	else
	{
		printf("exist!\n");
		fclose(fp);
	}

	return 0;
}