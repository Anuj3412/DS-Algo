#include <bits/stdc++.h>
using namespace std;


int sumArray(int arr[] , int n ){
    //base condition
    if(n==0)return 0;

    //recursive call
    return arr[n-1] + sumArray(arr, n-1);
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 5, 6, 8, 3};
    cout<<sumArray(arr , 5);
    return 0;
}
