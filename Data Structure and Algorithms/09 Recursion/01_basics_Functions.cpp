#include<bits/stdc++.h>
using namespace std;

// Factorial
int factorial(int n){
    if(n==1) return 1;  // base condiion
    else return n*factorial(n-1);  // recursive relation
}

// print 1 to n 
void print(int n){
    
    if (n > 0) // base condition 
    {
    print(n - 1); // recursive relation 
    cout << n << " ";  // processing 
    }
}

// x power n 
int power(int x , int n){
    if(n==0) return 1;  ///base condtion 

    return x*power(x , n-1);  // recursive relation 
}


int main(int argc, char const *argv[])
{
    int n = 5;
    cout<<"factorial of n is "<<factorial(n)<<endl;
    print(n);
    cout<<endl;
    cout<<"2 raised to power 5 is : "<<power(2 , 5)<<endl;
    return 0;

}
