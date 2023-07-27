#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2)

// we traverse the array and keep the current element to its actual position in backward direction
void insertation_sort(int *arr, int n)
{
    for (int i = 1; i < n ; i++)
    {
        int j = i-1;
        while(arr[j]>arr[i] and j>=0)
            swap(arr[i--], arr[j--]);

    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {99, 5, 8, 7, 4, 6, 7, 4, 1, 3};
    insertation_sort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}