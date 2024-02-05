#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int i = 0;

    while (i < n)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;
    i = 0;
    do
    {
        cout << i << " ";
        i++;
    } while (i <= n);

    cout<<endl;

    for(int i = 0; i<n ; i++){
        cout<<i<<" ";

        if(i==10) break;
    }

    return 0;
}