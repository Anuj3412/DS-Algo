#include <bits/stdc++.h>
using namespace std;

void reverse(string &s, int i)
{
    // cout<<"Before : "<<(s)<<endl;
    int n = s.size();
    // cout<<n<<endl;
    // base condition
    if (i >= n - 1 - i)
        return;

    swap(s[i], s[n - 1 - i]);
    // cout<<"After : "<<(s)<<endl;
    // recursive call
    reverse(s, i + 1);
}
int main(int argc, char const *argv[])
{
    string s = "Alphabet";
    int n = s.length();
    // cout<<n<<endl;
    reverse(s, 0);
    cout << "Final Answer is :" << s;
    return 0;
}
