#include <bits/stdc++.h>
using namespace std;

int pivot(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    // base condition
    if (s >= e)
        return s;

    // recursive call
    if (arr[mid] > arr[0])
        pivot(arr, mid, e);
    else if (arr[mid] < arr[0])
        pivot(arr, s, mid - 1);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
    cout << pivot(arr, 0, 9);
    return 0;
}
