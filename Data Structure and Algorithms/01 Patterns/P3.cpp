#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (i * n) + j << " ";
        }
        cout << endl;
    }

    cout << endl;
    int count = 1;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {

        int a = i;
        for (int j = 0; j < i; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }


    
    return 0;
}