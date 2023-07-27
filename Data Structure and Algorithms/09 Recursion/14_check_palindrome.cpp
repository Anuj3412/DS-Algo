#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string & s , int i , int n ){
    
    //base condition
    if( s[i]!= s[n-1-i]) return false;

    //recursive call
    checkPalindrome(s , i+1 , n);

    return true;

}

int main(int argc, char const *argv[])
{
    string s = "mom";
    string s1 = "maa";

    cout<<checkPalindrome(s , 0 , s.length())<<" "<<checkPalindrome(s1 , 0  , s1.length());
    return 0;
}
