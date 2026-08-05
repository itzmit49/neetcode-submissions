class Solution {
public:
    bool solve(int idx,vector<int>&nums,int tar,vector<vector<int>>&dp){
        if(tar==0)return true;
        if(idx>=nums.size())return false;
        if(dp[idx][tar]!=-1)return dp[idx][tar];
        int take=false;
        if(nums[idx]<=tar)take=solve(idx+1,nums,tar-nums[idx],dp);
        int nottake=solve(idx+1,nums,tar,dp);
        return dp[idx][tar]= take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2==1)return false;

        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));

        return solve(0,nums,sum/2,dp);
        
    }
};
