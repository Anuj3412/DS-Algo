#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2)

// we traverse the array and keep largest element at last position
void Bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n-i ; j++){
            if(arr[j]>arr[j+1]) swap(arr[j] , arr[j+1]);
            
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] = {99, 5, 8, 7, 4, 6, 7, 4, 1, 3};
    Bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}