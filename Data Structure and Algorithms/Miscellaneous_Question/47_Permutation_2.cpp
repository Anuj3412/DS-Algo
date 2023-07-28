#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int index, set<vector<int>> &ans)
{
    // base condition
    if (index >= nums.size())
    {
        ans.insert(nums);
        return;
    }

    // recursive call
    for (int i = index; i < nums.size(); i++)
    {   if(nums[index]==nums[i] and i!=index) continue;
        swap(nums[i], nums[index]);
        solve(nums, index + 1, ans);
        // backtracking --> ye isliye kar rahe h kyoki har baar sequence sahi rahe 
        // abc --> bac (this needs to be converted back to abc for) --> abc --> cba :: like this
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    set<vector<int>> ans;
    int index = 0;
    vector<vector<int>> vect;
    solve(nums, index, ans);
    for(auto it : ans){
        vect.emplace_back(it);
    }
    return vect;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 1, 1};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
