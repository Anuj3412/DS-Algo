#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[] , int n){
    //base conditon
    if(n==1)return true;
    if(arr[n-1]<arr[n-2]) return false;

    //recursive call
    isSorted(arr , n-1);




}
int main(int argc, char const *argv[])
{
    int arr[5] = {1,5,9,8,7};
    if(isSorted(arr , 5)) cout<<"YES";
    else cout<<"NO";
    return 0;
}
