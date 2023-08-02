#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseStringWordWise(string input)
{
    // Write your code here
    string ans = "";
    string temp = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ' or i==input.size()-1)
        {
            reverse(temp.begin(), temp.end());
            if(i==input.size()-1){
                ans=ans + temp;
                temp="";
                continue;
            }
            ans = ans + temp + ' ';
            temp = "";
            continue;
        }
        
        temp.push_back(input[i]);
        cout<<temp<<endl;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}