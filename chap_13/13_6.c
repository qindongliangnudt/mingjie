#include <stdio.h>

int main(int argc, const char* argv[])
{
	int ch;
	int line_num = 0;
	FILE *fp;
	char fname[64];
	
	printf("文件名: ");
	scanf("%s", fname);
	
	if (!(fp = fopen(fname, "r")))
	{
		printf("\a文件打开失败！\n");
	}
	else
	{
		while ((ch = fgetc(fp)) != EOF)
		{
			putchar(ch);
			if (ch == '\n')
			{
				line_num++;
			}
		}
		fclose(fp);
	}
	
	printf("文件%s一共有%d行\n", fname, line_num);	
	return 0;
}
