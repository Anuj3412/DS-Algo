#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

string removeConsecutiveDuplicates(string input)
{
    // Write your code here
    string ans;
    ans.push_back(input[0]);
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] == input[i - 1])
        {
            continue;
        }
        ans.push_back(input[i]);
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    string ans = removeConsecutiveDuplicates(str);
    cout << ans << endl;
}