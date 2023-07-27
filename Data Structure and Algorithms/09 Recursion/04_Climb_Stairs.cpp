#include<bits/stdc++.h>
using namespace std;

int climbstairs(int n ){
    //base conditon 
    if(n==0) return 1;
    if(n<0) return 0;

    // recursive call
    return climbstairs(n-1 ) + climbstairs(n-2);
     
}

// theory : we just take the case when person is on single step -> he has two choices jump by one or two 
// considering both options and adding them
// base condition : when person is on 0th step he has only one option to reach 

int main(int argc, char const *argv[])
{
    int n=5;
    cout<<climbstairs(n );
    return 0;
}
