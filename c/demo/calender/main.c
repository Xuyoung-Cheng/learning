#include <stdio.h>

#define LE_YEAR 1

int isleap(int y)
{
	return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
}

int max_day(int y, int m)
{
	int ret;
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	ret = isleap(y);
	if (ret == LE_YEAR)
		month[1] = 29;

	return month[m - 1];
}

int total_day(int y, int m, int d)
{
	int sum;
	int i;

	sum = 0;
	for (i = 1; i < m; i++)
	{
		sum += max_day(y, i);
	}
	sum += d;

	return sum;
}

int main(int argc, char *argv[])
{
	int year = 0, month = 0, day = 0;
	int ret = 0;

	printf("please input [year month day] : ");
	scanf("%d%d%d", &year, &month, &day);

	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		printf("Input date is error!\n");
		return -1;
	}
	
	ret = isleap(year);
	if (ret == LE_YEAR)
		printf("%d-%d-%d is leap year\n", year, month, day);
	else
		printf("%d-%d-%d is not leap year\n", year, month, day);
	
	ret = total_day(year, month, day);
	printf("%d-%d-%d is %d day of the year\n", year, month, day, ret);
	return 0;
}
