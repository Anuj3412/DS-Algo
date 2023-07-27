#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(n)
int main(int argc, char const *argv[])
{
    int arr[10]={123,31,5,46,8,4,1,34,64,31};
    int key = 8;
    for(int i = 0 ; i< 10 ; i++){
        if(arr[i]==key) {
            cout<<"Is Present";
            return 0;
        }
    }
    cout<<"Not Found";
    return 0;
}
