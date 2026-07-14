class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&nums,int tar,vector<int>temp){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        if(tar<0|| idx>=nums.size())return;
        temp.push_back(nums[idx]);
        solve(idx+1,nums,tar-nums[idx],temp);
        temp.pop_back();
        while(idx+1<nums.size()&& nums[idx]==nums[idx+1])idx++;
        solve(idx+1,nums,tar,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        solve(0,candidates,target,{});


        return ans;
        
    }
};
