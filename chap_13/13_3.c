#include <stdio.h>
#include <time.h>

int main (int argc, const char *argv[])
{
	FILE *fp;
	time_t t;
	struct tm *local;
	
	time(&t);
	local = localtime(&t);
	
	if ((fp = fopen("dt.dat", "w")) == NULL)
	{
		printf("\a file open failed!\n");
	}
	else
	{
		printf("write the current date and time:\n");
		fprintf(fp, "%d %d %d %d %d %d\n", 
			local->tm_year + 1990, local->tm_mon + 1, local->tm_mday, 
			local->tm_hour, local->tm_min, local->tm_sec);
		fclose(fp);
	}
	return 0;
}
