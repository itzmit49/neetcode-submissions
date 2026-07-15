class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&nums,vector<int>temp){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(idx+1,nums,temp);
        while(idx+1<nums.size()&&nums[idx]==nums[idx+1])idx++;
        temp.pop_back();
        solve(idx+1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        solve(0,nums,{});

        return ans;

        
    }
};
