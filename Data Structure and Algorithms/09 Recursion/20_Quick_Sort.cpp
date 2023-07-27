#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{

    int a = arr[s];

    // correct poistion find karo
    int cnt = 0;
    for (int i = s+1; i <=e; i++)
    {
        if (arr[i] < a)
            cnt++;
    }

    // swap kar do us ki position par
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    // left or right ko sahi karo
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

void quick_sort(int arr[], int s, int e)
{

    // base condition
    if (s >= e)
        return;

    // partition bana lete h
    int p = partition(arr, s, e);

    // left vala sort kar do
    quick_sort(arr, s, p - 1);

    // right vala sort kar do
    quick_sort(arr, p + 1, e);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {45, 45, 8, 7, 634, 6, 4, 1, 3, 49};
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}
