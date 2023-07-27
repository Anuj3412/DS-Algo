#include<bits/stdc++.h>
using namespace std;

void solve(string str, string out, int index, vector<string> &ans)
{
    // base condition
    if (index >=str.length())
    {
        if (out.length() == 0)
            return;
        ans.push_back(out);
        return;
    }

    // exclude
    solve(str, out, index + 1, ans);

    // include
    char temp = str[index];
    out.push_back(temp);
    solve(str, out, index + 1, ans);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string out = "";
    int index = 0;
    solve(str, out, index, ans);
    return ans;
    // Write your code here
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    vector<string> str = subsequences(s);
    for(int i =0  ; i< str.size() ; i++) cout<<str[i]<<" ";
    return 0;
}



