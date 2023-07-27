#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    // base condition
    if (n == 0)
        return 1;

    // recursive call
    return x * power(x, n - 1);
}

int Opower(int x, int n)
{
    // base condition
    if (n == 0)
        return 1;

    // processing
    int temp = Opower(x, n / 2);

    // recursive call

    if (n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}


int main(int argc, char const *argv[])
{
    int x = 5, n = 5;
    cout << Opower(x, n);
    return 0;
}
