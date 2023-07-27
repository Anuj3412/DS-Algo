#include<bits/stdc++.h>
using namespace std;

// nth fibonnci number
int fibonacci(int n ){
    
    // base condition 
    if(n==2) return 1;
    if(n==1) return 0;

    // recursive relation
    return fibonacci(n-1) + fibonacci(n-2);

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<"nth fibonnaci number is : "<<fibonacci(n)<<endl;
    return 0;
}
