#include <bits/stdc++.h>
using namespace std;

int main()
{

    // int arr[5];
    // for (int i = 0; i < 5; i++)
    // {

    //     cin >> arr[i];
    // }
    // for(int i = 0 ; i< 5 ; i++){
    // cout << arr[i] << endl;
    // }

    vector<int> v;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "hi" << endl;
    int max = v[0];
    for (int i = 1; i < n; i++)
    {
        if (max < v[i])
        {
            cout << "hi" << endl;
            max = v[i];
        }
    }
    cout << max << endl;

    return 0;
}