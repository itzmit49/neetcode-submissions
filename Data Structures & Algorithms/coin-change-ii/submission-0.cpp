class Solution {
public:
    int solve(int idx,int tar,vector<int>&coins,vector<vector<int>>&dp){
        if(tar==0)return 1;
        if(idx>=coins.size())return 0;
        if(dp[idx][tar]!=-1)return dp[idx][tar];
        int nottake=solve(idx+1,tar,coins,dp);
        int take=0;
        if(coins[idx]<=tar)take=solve(idx,tar-coins[idx],coins,dp);
        return dp[idx][tar]= take+nottake;
        
    }
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(0,amount,coins,dp);

        
    }
};
