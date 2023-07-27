#include<bits/stdc++.h>
using namespace std;

int peak(int *arr , int s , int e){
    int mid = s + (e-s)/2;
    //base condition 
    if(s>e) return e;
    if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1]) return mid;

    //recursive call
    if(arr[mid]>arr[mid+1]) peak(arr , s , mid);
    else if(arr[mid]<arr[mid+1]) peak(arr , mid+1 , e);
}

int main(int argc, char const *argv[])
{
    int arr[7] = {1,2,3,4,5,6,7};
    cout<<peak(arr, 0 , 6);
    return 0;
}
