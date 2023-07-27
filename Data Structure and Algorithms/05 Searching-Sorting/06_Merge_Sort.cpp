// Time Complexity : O(nlogN)
// Space Complexity : O(n)  as in worst case we divide full array and to store their half we use n/2 n/2 memory

#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // copy karo
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merging
    int a = 0, b = 0;
    k = s;
    while (a < len1 and b < len2)
    {
        if (first[a] < second[b])
            arr[k++] = first[a++];
        else
            arr[k++] = second[b++];
    }

    while (a < len1)
    {
        arr[k++] = first[a++];
    }

    while (b < len2)
    {
        arr[k++] = second[b++];
    }

    // we delete this heap memory after use
    delete[] first;
    delete[] second;
}

void merge_sort(int *arr, int s, int e)
{

    // base condition
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // recursive call
    // left sort karo
    merge_sort(arr, s, mid);

    // right sort karo
    merge_sort(arr, mid + 1, e);

    // processing
    merge(arr, s, e);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {6, 8, 64, 3, 1, 4, 9, 646, 6449, 879};
    merge_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}
