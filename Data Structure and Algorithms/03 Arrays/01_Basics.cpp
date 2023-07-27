#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{   
    int n = 10;
    int arr[10]={1,2,5,4,8,7,9,65,633,5}; //initialising an array with the 10 elements
    int arr1[10]; //initialising array with size 10 --> it has garbage values
    int arr2[n]; //initalising array with variable size
    int arr3[10] = {}; //initialising array with all elements as zero
    for(int i =0 ; i< 10 ; i++) cout<<arr[i]<<" ";
    cout<<endl; 
    for(int i =0 ; i< 10 ; i++) cout<<arr1[i]<<" "; 
    cout<<endl; 
    for(int i =0 ; i< 10 ; i++) cout<<arr3[i]<<" "; 
    return 0;
}
