class Solution {
public:
    bool solve(int idx,vector<int>&nums,vector<int>&dp){
        
        if(idx>=nums.size()-1)return true;
        if(dp[idx]!=-1)return dp[idx];
        

        int jump=nums[idx];
        if(jump==0)return dp[idx]= false;
        for(int i=1;i<=jump;i++){
            if(solve(i+idx,nums,dp))return dp[idx]= true;
        }
        return dp[idx]= false;


    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);

        return solve(0,nums,dp);


        
    }
};
