class Solution {
public:
    int solve(int i, int j, string &a, string &b,vector<vector<int>>&dp) {
        if (i == a.size()) return b.size() - j;
        if (j == b.size()) return a.size() - i;
        if(dp[i][j]!=-1)return dp[i][j];
        if (a[i] == b[j])
            return solve(i + 1, j + 1, a, b,dp);

        return dp[i][j]= 1 + min({
            solve(i + 1, j + 1, a, b,dp), 
            solve(i + 1, j, a, b,dp),     
            solve(i, j + 1, a, b,dp)      
        });
    }

    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0, 0, word1, word2,dp);
    }
};