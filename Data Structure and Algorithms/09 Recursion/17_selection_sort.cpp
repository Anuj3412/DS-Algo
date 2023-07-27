#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *arr , int n){

    //base condition 
    if(n==1)return;

    //processing
    int maxIndex=0;
    for(int i = 0 ; i< n ; i++){
        if(arr[i]>arr[maxIndex]) maxIndex= i;
    }
    swap(arr[n-1] , arr[maxIndex]);

    //recursive call
    selection_sort(arr , n-1);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {5,4,8,8,7,6,4,65,32,6};
    selection_sort(arr , 10);
    for(int i =0 ; i< 10 ; i++) cout<< arr[i]<<" ";
    return 0;
}
