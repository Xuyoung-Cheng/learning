#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 5, 1, 3, 2, 6 };

void insertion_sort(void)
{
    int i, j, key;
    for (j = 1; j < LEN; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main()
{
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
            a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    insertion_sort();
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
            a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);

    return 0;
}