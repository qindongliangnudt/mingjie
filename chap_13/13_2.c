#include <stdio.h>

int main (int argc, const char *argv[])
{
	FILE* fp;
	int ninzu = 0;
	char name[100];
	double height, weight;
	double hsum;
	double wsum;

	if ((fp = fopen("13_2.dat", "r")) == NULL)
		printf("\aFAILED OPEN!\n");
	else
	{
		while (fscanf(fp, "%s%lf%lf", name, &height, &weight) == 3)
		{
			printf("%-10s %5.1f %5.1f\n", name, height, weight);
			ninzu++;
			hsum += height;
			wsum += weight;
		}
		printf("----------------------\n");
		printf("Average:	%5.1f %5.1f", hsum / ninzu, wsum / ninzu);
		fclose(fp);
	}
	return 0;
}