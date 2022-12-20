#include <stdio.h>

#define DEBUG 1

enum day
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

char get_last_char(char str[])
{
    char c;
    int i = 0;

    while (str[i])
        c = str[i++];

    return c;
}

int is_restricted(int tail_num, enum day d)
{
    int ret = 0;

    switch (tail_num)
    {
    case 0:
    case 5:
        ret = (d == MONDAY) ? 1 : 0;
        break;
    case 1:
    case 6:
        ret = (d == TUESDAY) ? 1 : 0;
        break;
    case 2:
    case 7:
        ret = (d == WEDNESDAY) ? 1 : 0;
        break;
    case 3:
    case 8:
        ret = (d == THURSDAY) ? 1 : 0;
        break;
    case 4:
    case 9:
        ret = (d == FRIDAY) ? 1 : 0;
        break;
    default:
        ret = 0;
        break;
    }

    return ret;
}

enum day get_week_day(int y, int m, int d)
{
    enum day wd = MONDAY;

    if (m == 1 || m == 2)
    {
        m = m + 12;
        y = y - 1;
    }

    wd = (d + 2*m + 3*(m + 1)/5 + y + y/4 - y/100 + y/400 + 1) % 7;

#if DEBUG
    printf("[DEBUG] - today is < %d >\n", wd);
#endif

    return wd;
}

int main(void)
{
    char car_num_str[8];
    char last_char;
    enum day d;                                                                 /* 1-7 */
    int tail_num;                                                               /* "A23456" -> 6 */
    int ret;

    printf("please input your car number: \n");
    scanf("%s", car_num_str);

    printf("car number is %s\n", car_num_str);

    /* get last char of car number */
    last_char = get_last_char(car_num_str);

#if DEBUG
    printf("[DEBUG] - last char = < %c >\n", last_char);
#endif

    tail_num = last_char - '0';
    d = get_week_day(2022, 12, 20);
    ret = is_restricted(tail_num, d);
    if (ret == 1)
        printf("restricted!\n");
    else
        printf("NOT restricted!\n");

    return 0;
}