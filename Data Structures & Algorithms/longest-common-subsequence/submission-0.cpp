class Solution {
public:
    int solve(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
        if(i>=s1.size()||j>=s2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int way1=0;
        if(s1[i]==s2[j]){
            way1=1+solve(i+1,j+1,s1,s2,dp);
        }
        int way2=solve(i+1,j,s1,s2,dp);
        int way3=solve(i,j+1,s1,s2,dp);
        return dp[i][j]= max({way1,way2,way3});

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(0,0,text1,text2,dp);
        
    }
};
