#include <stdio.h>

#define LEN 7

int array[LEN] = {49, 38, 65, 97, 76, 13, 27};

int partition(int start, int end)
{
    int pivotkey = array[start];

    while (start < end)
    {
        while (start < end && array[end] >= pivotkey)
            end--;
        array[start] = array[end];
        while (start < end && array[start] <= pivotkey)
            start++;
        array[end] = array[start];
    }
    array[start] = pivotkey;

    return start;
}

void order_statistic(int start, int end, int k)
{
    int mid, i;

    mid = partition(start, end);
    i = mid - start + 1; //pivotkey是第几小的

    if (k == i)
    {
        printf("the k-th low is %d\n", array[mid]);
    }
    else if (k > i)
    {
        order_statistic(mid+1, end, k-i);
    }
    else
    {
        order_statistic(start, mid-1, k);
    }

    return;
}

int main(void)
{
    order_statistic(0, LEN-1, 1);
    order_statistic(0, LEN-1, 2);
    order_statistic(0, LEN-1, 3);
    order_statistic(0, LEN-1, 4);
    order_statistic(0, LEN-1, 5);
    order_statistic(0, LEN-1, 6);
    order_statistic(0, LEN-1, 7);

    return 0;
}