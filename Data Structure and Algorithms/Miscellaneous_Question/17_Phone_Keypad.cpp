#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string str, int index, vector<string> &map, vector<string> &ans)
{
    // base condition
    if (index >= digits.length())
    {
        ans.push_back(str);
        return;
    }

    int digit = digits[index] - '0'; // kaunsa number h keypad me
    string s = map[digit];           // us number k corresponding kya string h
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        str.push_back(c);
        solve(digits, str, index + 1, map, ans);
        str.pop_back(); //str ko empty karna hoga varna vo element bhi rahega
    }
}

vector<string> keypad(string digits)
{
    vector<string> ans;
    int index = 0;
    string str;
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, str, index, map, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    string digits = "23";
    vector<string> ans = keypad(digits);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
