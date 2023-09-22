#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int key)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] >= key)
            e = mid;
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

int main()
{

    vector<int> nums = {1, 3, 4, 4, 5, 5, 5, 5, 10, 19, 20, 211};
    int key = 4;
    // cin>>key;
    int ans = firstOccurence(nums, key);
    cout << ans;

    return 0;
}