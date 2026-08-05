class Solution {
public:
    int solve(int idx,vector<int>&nums,int prevIdx,vector<vector<int>>&dp){
        if(idx>=nums.size())return 0;
        if(dp[idx][prevIdx+1]!=-1)return dp[idx][prevIdx+1];
         int nottake=solve(idx+1,nums,prevIdx,dp);
        int take=0;
        if(prevIdx==-1||nums[idx]>nums[prevIdx])take=1+solve(idx+1,nums,idx,dp);
       
        return dp[idx][prevIdx+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(0,nums,-1,dp);
        
    }
};
