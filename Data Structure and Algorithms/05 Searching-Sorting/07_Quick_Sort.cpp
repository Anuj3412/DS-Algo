#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    // select pivot
    int a = arr[s];

    // find correct position of pivot
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < a)
            cnt++;
    }
    // swap kardo
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    // left vale smaller or right vale bigger kar do
    int i = s, j = e;
    while (i < pivotIndex and j > pivotIndex)
    {

        while (arr[i] < arr[pivotIndex])
            i++;
        while (arr[j] > arr[pivotIndex])
            j--;

        if (i < pivotIndex and j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quick_sort(int *arr, int s, int e)
{
    // base condition
    if (s >= e)
        return;

    // partition kar do
    int p = partition(arr, s, e);

    // left sort kr do
    quick_sort(arr, s, p - 1);

    // right sort kar do
    quick_sort(arr, p + 1, e);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {54, 6, 5, 4, 6, 3, 1, 46, 4, 63};
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}
