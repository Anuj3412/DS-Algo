#include <bits/stdc++.h>
using namespace std;

int b = 10; // this is a global variable which can be accessed throughout the code

int main(int argc, char const *argv[])
{
    int a = 5;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    return 0;
}

// this is a bad practise as it can be changed anywhere in code