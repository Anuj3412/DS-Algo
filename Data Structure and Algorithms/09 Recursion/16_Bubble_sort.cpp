#include<bits/stdc++.h>
using namespace std;

void bubbble_sort(int *arr , int n ){
   //base condition
   if(n==1 or n==0) return;
   
   //recursive call
   bubbble_sort(arr+1 , n-1);

   //processing 
    for(int i = 0 ; i< n-1 ; i++){
        if(arr[i]>arr[i+1]) swap(arr[i] , arr[i+1]);
    }
}
int main(int argc, char const *argv[])
{
    int arr[1]={4};
    bubbble_sort(arr , 1);
    for(int i = 0 ; i < 1 ; i++) cout<<arr[i]<<" ";
    return 0;
}
