#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, int sum, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base condition
    if (index >= candidates.size())
    {
        return;
    }
    else if (sum == target)
    {
        ans.push_back(output);
        return;
    }
    else if (sum > target)
        return;

    // recursive call
    output.push_back(candidates[index]);
    solve(candidates, target, sum + candidates[index], output, index, ans);
    output.pop_back();
    solve(candidates, target, sum, output, index + 1, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(candidates, target, 0, output, index, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> str = {12, 5, 46, 8, 79, 4, 61, 6, 49, 79};
    int target = 17;
    vector<vector<int>> ans = combinationSum(str, target);
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
