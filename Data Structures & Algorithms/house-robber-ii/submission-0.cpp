class Solution {
public:
    int solve(int idx,int stop,vector<int>&nums,vector<int>&dp){
        if(idx>stop)return 0;
        if(dp[idx]!=-1)return dp[idx];

       int take=nums[idx]+solve(idx+2,stop,nums,dp);
       int nottake=solve(idx+1,stop,nums,dp);
       return dp[idx]= max(take,nottake);
       
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        vector<int>dp1(nums.size(),-1);
         vector<int>dp2(nums.size(),-1);
        
        return max( solve(0,n-2,nums,dp1),solve(1,n-1,nums,dp2));
        
    }
};
