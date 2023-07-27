#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(nLogN)

bool binary_search(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {

        mid = s + (e - s) / 2;
        // base case
        if (arr[mid] == key)
        {
            return true;
        }

        // compare
        if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    int arr[10] = {123, 31, 5, 46, 8, 4, 1, 34, 64, 31};
    sort(arr, arr + 10);
    int key = 87;
    if (binary_search(arr, 10, key))
        cout << "Is Present";
    else
        cout << "Not Found";
    return 0;
}
