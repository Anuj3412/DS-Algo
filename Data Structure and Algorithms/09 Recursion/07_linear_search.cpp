#include<bits/stdc++.h>
using namespace std;

// yaha pointer pass kiya h 
// no need to for extra memory usage 
bool isFound(int *arr , int n , int key){
    //base condition
    if(arr[0]==key) return true;
    if(n==0) return false;

    //recursive call
    isFound(arr+1 , n-1 , key);
}

int main(int argc, char const *argv[])
{
    int arr[7]={1,5,6,8,7,4,56};
    if(isFound(arr , 7 , 7)) cout<<"Is Found";
    else cout<<"Not Found";
    return 0;
}
