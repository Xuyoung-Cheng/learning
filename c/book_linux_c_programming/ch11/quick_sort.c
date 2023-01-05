#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 5, 1, 3, 2, 6 };

void swap(int i, int j)
{
    a[i] ^= a[j];
    a[j] ^= a[i];
    a[i] ^= a[j];
}

int partition(int start, int end)
{
    int pivot = a[start];

    while (start < end) {
        while (start < end && a[end] >= pivot) 
            end--;
        a[start] = a[end];
        while (start < end && a[start] <= pivot) 
            start++;
        a[end] = a[start];
    }
    a[start] = pivot;

    return start;
}

void quicksort(int start, int end)
{
    int mid;
    if (end > start) {
        mid = partition(start, end);
        quicksort(start, mid-1);
        quicksort(mid+1, end);
    }
}

int main()
{
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
            a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    quicksort(0, LEN-1);
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
            a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);

    return 0;
}