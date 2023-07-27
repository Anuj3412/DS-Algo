#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr , int n){
    //base condition
    if(n==1) return;

    //recursive call 
    insertion_sort(arr , n-1);

    //processing
    for(int i = n-1 ; i > 0 ; i-- ){
        if(arr[i]<arr[i-1]) swap(arr[i], arr[i-1]);
        else break;
    }
}

int main(int argc, char const *argv[])
{
    int arr[10] ={64,6,488,3,1,4,564,321,46,3};
    insertion_sort(arr , 10);
    for(int i=0 ; i<10 ;  i++) cout<< arr[i]<<" ";
    return 0;
}
