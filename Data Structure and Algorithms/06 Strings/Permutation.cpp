#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int index, vector<string> &ans)
{
    // base conditon
    if (index >= str.length())
    {
        ans.push_back(str);
        return;
    }

    // recursive call
    for (int i = index; i < str.length(); i++)
    {
        swap(str[i], str[index]);
        solve(str, index + 1, ans);
        // backtracking --> returning to previous state for another swap
        swap(str[i], str[index]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    int index = 0;
    solve(str, index, ans);
    sort(ans.begin(), ans.end()); // to get them in lexicographical order
    return ans;
}
int main(int argc, char const *argv[])
{
    string str = "abc";
    vector<string> ans = generatePermutations(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
