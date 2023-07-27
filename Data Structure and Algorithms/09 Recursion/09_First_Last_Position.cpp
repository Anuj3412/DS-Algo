#include <bits/stdc++.h>
using namespace std;

int lastPos(int *arr , int s , int e , int key){

    //base condition
    if(s>e) return e;
    int mid = s + (e - s) / 2;

    if(arr[mid]==key) return lastPos(arr , mid+1 , e , key );

    // recursive call
    if(arr[mid]<key) lastPos(arr , mid+1  , e ,key);
    else if (arr[mid]>key) lastPos(arr , s , mid -1 , key );

}

int firstPos(int *arr, int s, int e, int key)
{
    // cout << s << " " << e << " ";
    // base condition
    if (s > e)
        return s;
    int mid = s + (e - s) / 2;
    // cout << mid << endl;
    if (arr[mid] == key)
        return firstPos(arr, s, mid - 1, key);

    // recurisve call
    if (arr[mid] > key)
        firstPos(arr, s, mid - 1, key);
    else if (arr[mid] < key)
        firstPos(arr, mid + 1, e, key);
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1, 2, 2, 3, 6, 5, 5, 7, 2, 2};
    sort(arr, arr + 10);
    cout << firstPos(arr, 0, 9, 1)<<endl;
    cout << lastPos(arr, 0, 9, 0);

    return 0;
}
