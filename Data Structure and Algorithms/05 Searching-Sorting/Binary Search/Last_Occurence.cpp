#include <bits/stdc++.h>
using namespace std;

int lastOccurence(vector<int> &nums, int key)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int result = -1; // Initialize result to -1 in case the key is not found

    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (nums[mid] == key)
        {
            result = mid; // Update result to the current index
            s = mid + 1;  // Continue searching on the right side
        }
        else if (nums[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return result;
}

int main()
{

    vector<int> nums = {1, 3, 4, 4, 5, 5, 5, 5, 10, 19, 20, 211};
    int key = 4;
    int ans = lastOccurence(nums, key);
    cout << ans;

    return 0;
}
