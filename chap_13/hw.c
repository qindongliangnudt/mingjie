#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int islegal_name(const char*);
void put_data(int);
int  get_data(void);

int main(int argc, const char* argv[])
{
	char str_line[256];
	char name[128];
	char height[50];
	char weight[50];
	
	float f_height;
	float f_weight;
	float bmi;
	
	int i = 0;
	int i_name = 0;
	int i_height = 0;
	int i_weight = 0;
	int count = 0;
	int identifier = 0;
	
	time_t t;
	struct tm *local;
	int run_times;
	
	run_times = get_data() + 1;
	printf("这是程序第%d次运行...\n", run_times);
	put_data(run_times);
	
	FILE* rt;
	FILE* fp;
	
	while ((fgets(str_line, sizeof(str_line), stdin)) != NULL)
	{
		i = 0;
		i_name = 0;
		i_height = 0;
		i_weight = 0;
		count = 0;
		identifier = 0;
		
		while (str_line[i] != '\0')
		{
			if (!isblank(str_line[i]) && str_line[i] != '\n')
			{
				identifier = 0;
				if (count == 0)
				{
					name[i_name++] = str_line[i];
				}
				else if (count == 1)
				{
					height[i_height++] = str_line[i];
				}
				else if (count == 2)
				{
					weight[i_weight++] = str_line[i];
				}
			}
			else if (identifier == 0)
			{
				identifier = 1;
				count++;
			}
		
			i++;
		}
		name[i_name] = '\0';
		height[i_height] = '\0';
		weight[i_weight] = '\0';
		if (!islegal_name(name))
		{
			printf("名字不合法，写入文件失败！\n");
			continue;
		}
		
		if ((f_height = atof(height)) < 1.0)
		{
			printf("身高不合法，写入文件失败！\n");
			continue;
		}
		
		
		if ((f_weight = atof(weight)) < 1.0)
		{
			printf("体重不合法，写入文件失败！\n");
			continue;
		}
			
		bmi = f_weight * 10000.0 / (f_height * f_height);
		
		time(&t);
		local = localtime(&t);
		
		
		if (!(fp = fopen("hw.dat", "a")))
			printf("\a文件打开失败！\n");
		else 
		{
			fprintf(fp, "%20s	%.2f	%.2f	%.3f	%d	%d-%d-%d/%d:%d:%d\n", name, f_height, f_weight, bmi, run_times, 
					local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
			fclose(fp);
			printf("成功写入一条合法数据！\n");
		}
	}
	
	return 0;
}

int islegal_name(const char* name)
{
	int i = 0;
	int number = 1;
	while(name[i] != '\0')
	{
		if (!isalpha(name[i++]))
		{
			number = 0;
			break;
		}
	}
	return (i && number);
}

int get_data(void)
{
	FILE* rt;
	int times = 0;
	
	if (!(rt = fopen("hw.rt", "r")))
	{
		return 0;
	}
	else
	{
		fscanf(rt, "%d", &times);
		fclose(rt);
	}
	return times;
}

void put_data(int times)
{
	FILE* rt;
	if (!(rt = fopen("hw.rt", "w")))
	{
		printf("\a文件打开失败...\n");
	}
	else
	{
		fprintf(rt, "%d\n", times);
		fclose(rt);
	}
}




