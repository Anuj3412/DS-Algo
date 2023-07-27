#include<bits/stdc++.h>
using namespace std;

void solve(string s , string str , int index , vector<string> &ans){

    //base condition
    if(index>=s.length()){
        ans.push_back(str);
        return;
    }

    //exclude
    solve(s , str , index+1 , ans);

    //include
    char c = s[index];
    str.push_back(c);
    solve(s , str , index+1 , ans);

}

vector<string> subsequence(string s){
    vector<string> ans;
    string str;
    int index =0 ;
    solve(s , str , index , ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "abcd";
    vector<string> ans = subsequence(s);
    for(int i = 0 ; i< ans.size() ; i++) cout<<ans[i]<<" ";
    return 0;
}
