#include <stdio.h>

char str[] = "hello world";

int indexof(char letter)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == letter)
            return i;
        i++;
    }
    return -1;
}

int main(void)
{
    printf("%d %d\n", indexof('o'), indexof('z'));
    return 0;
}