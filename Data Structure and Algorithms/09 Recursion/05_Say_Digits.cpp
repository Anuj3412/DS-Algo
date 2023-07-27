#include<bits/stdc++.h>
using namespace std;

void sayDigits(int n , string arr[]){

    //base condition
    if(n==0) return;

    // recursive call
    sayDigits(n/10 , arr);
    cout<<arr[n%10]<<" ";
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string arr[10]={"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
    sayDigits(n  , arr);    
    return 0;
}
