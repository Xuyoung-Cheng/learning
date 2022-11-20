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

// Kim larsen calculation formula
int weekday(int y, int m, int d)
{
	int count = 0;

	if (m == 1 || m == 2) {
		m = m + 12;
		y = y - 1;
	}

	count = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;

	return count;
}

void display_week(int y, int m, int d)
{
	int count = 0;

	count = weekday(y, m, d);

	switch (count) {
	case 0:
		printf("%d-%d-%d is Sunday\n", y, m, d);
		break;
	case 1:
		printf("%d-%d-%d is Monday\n", y, m, d);
		break;
	case 2:
		printf("%d-%d-%d is Tuesday\n", y, m, d);
		break;
	case 3:
		printf("%d-%d-%d is Wednesday\n", y, m, d);
		break;
	case 4:
		printf("%d-%d-%d is Thursday\n", y, m, d);
		break;
	case 5:
		printf("%d-%d-%d is Firday\n", y, m, d);
		break;
	case 6:
		printf("%d-%d-%d is Saturday\n", y, m, d);
		break;
	}
}

void display_month(int y, int m, int d)
{
	int w = 0;;
	int i = 0;
	int max = 0;

	w = weekday(y, m, 1);
	max = max_day(y, m);

	printf("\n\t\t%d year %d month\n", y, m);
	printf("SUN  MON  TUE  WED  THU  FRI  SAT\n");

	for (i = 0; i < w; i++) {
		printf("     ");
	}
	
	for (i = 1; i <= max; i++) {
		if (i == d)
			printf("\033[1;43m%-2d\033[0m   ", i);
		else
			printf("%-5d", i);
		if ((w + i) % 7 == 0)
			printf("\n");
	}

	printf("\n");
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

	display_week(year, month, day);
	display_month(year, month, day);
	return 0;
}
