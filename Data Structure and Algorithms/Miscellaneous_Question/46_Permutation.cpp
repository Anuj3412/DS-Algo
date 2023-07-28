#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums , int index , vector<vector<int>> & ans){
    //base condition
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }

    //recursive call
    for(int i = index ; i< nums.size() ; i++){
        swap(nums[i] , nums[index]);
        solve(nums , index+1 , ans);
        //backtracking
        swap(nums[i] , nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans ;
    int index = 0;
    solve(nums , index , ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,1,3};
    sort(nums.begin() , nums.end());
    vector<vector<int>> ans = permute(nums);
    for(int i = 0 ; i< ans.size() ; i++){
        for(int j = 0 ; j< ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
