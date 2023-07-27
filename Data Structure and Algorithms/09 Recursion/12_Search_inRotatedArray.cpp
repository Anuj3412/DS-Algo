#include<bits/stdc++.h>
using namespace std;

int pivot(int *arr , int s , int e){
    int mid = s + (e - s )/2;

    // base condition
    if(arr[mid]>arr[mid+1]) return mid;

    //recursive call
    if(arr[mid]>arr[0]) pivot(arr , mid+1 , e );
    else if(arr[mid]<arr[0]) pivot(arr , s , mid );
}


int isPresent(int *arr , int s , int e , int key ){
    int mid = s + ( e - s )/2;
    //base case 
    if(s>e) return -1;
    if(arr[mid]==key) return mid;

    //recursive call
    if(key<arr[mid] and key > arr[0]) isPresent(arr , s , mid , key);
    else if(key>arr[mid] and key > arr[0]) isPresent(arr , s , mid , key);

}

int main(int argc, char const *argv[])
{
    int arr[10]= {7,8,9,0,1,2,3,4,5,6};
    int pivotpoint = pivot(arr , 0 , 9);
    int key = 11;
    if(key>arr[pivotpoint]) cout<< "-1";
    else if(key < arr[0]) cout<<isPresent(arr , pivotpoint+1 , 9 , key );
    else if(key > arr[9]) cout<<isPresent(arr , 0 , pivotpoint , key);

    return 0;
}
