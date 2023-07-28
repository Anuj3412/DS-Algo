/*  Time Complpexity : O(logN)  */

#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int s, int e)
{
    for (int i = s; i < e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool isFound(int *arr, int s, int e, int key)
{

    print(arr, s, e); // flow of array being passed 

    int mid = s + (e - s) / 2;
    // base condition
    if (arr[mid] == key)
        return true;
    // cout << arr[mid] << " ";
    if (s >= e)
        return false;

    // recursive call
    if (arr[mid] > key)
        isFound(arr, s, mid - 1, key);
    else if (arr[mid] < key)
        isFound(arr, mid + 1, e, key);
}
int main(int argc, char const *argv[])
{
    int arr[8] = {1, 3, 5, 14, 18, 27, 29, 36};
    if (isFound(arr, 0, 7, 18))
        cout << "Is Found";
    else
        cout << "Not Found";

    return 0;
}
