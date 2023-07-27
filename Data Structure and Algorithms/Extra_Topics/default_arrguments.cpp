#include <bits/stdc++.h>
using namespace std;

// we have declared the default value for start
void func(int arr[], int n, int start = 0)
{
    for (int i = start; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main(int argc, char const *argv[])
{

    int arr[9] = {1, 2, 4, 5, 676, 2345, 489};
    func(arr, 9); // since user has not provided the value for start, it will use default value

    return 0;
}