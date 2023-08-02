#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string reverseEachWord(string input)
{
    // Write your code here
    string ans = "";
    string temp = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ' or i == input.size() - 1)
        {
            if (i == input.size() - 1)
            {
                temp.push_back(input[i]);
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                temp = "";
                continue;
            }
            reverse(temp.begin(), temp.end());
            ans = ans + temp + ' ';
            temp = "";
            continue;
        }
        temp.push_back(input[i]);
    }
    return ans;
}

int main()
{

    string str = "Welcome to Coding Ninjas";
    // getline(cin, str);
    string ans = reverseEachWord(str);
    cout << ans << endl;
    return 0;
}

/* TWO Pointer Approach */

string reverse_EachWord(string input)
{
    int start = 0;
    int end = 0;

    while (end < input.size())
    {
        if (input[end] == ' ')
        {
            reverse(input.begin() + start, input.begin() + end);
            start = end + 1;
        }
        end++;
    }

    reverse(input.begin() + start, input.begin() + end); // Reverse the last word

    return input;
}
