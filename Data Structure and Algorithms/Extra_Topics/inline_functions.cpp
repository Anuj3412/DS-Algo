#include <bits/stdc++.h>
using namespace std;

// functions less than 3 lines can be defined as macros  i.e. in one line

// this is a ternary operator 
// syntax :   (condition here) ? true output : false output

#define max(a , b) (a > b) ? a : b

int main(int argc, char const *argv[])
{
    int a = 5, b = 6;
    int ans = max(a, b);
    cout<<ans;
    return 0;
}
