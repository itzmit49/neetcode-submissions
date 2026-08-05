class Solution {
public:
    int solve(int idx, vector<int>& prices, int buy, vector<vector<int>>& dp) {
        if (idx >= prices.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        int profit;

        if (buy) {
            profit = max(
                -prices[idx] + solve(idx + 1, prices, 0, dp), // Buy
                solve(idx + 1, prices, 1, dp)                 // Skip
            );
        } else {
            profit = max(
                prices[idx] + solve(idx + 2, prices, 1, dp),  // Sell
                solve(idx + 1, prices, 0, dp)                 // Skip
            );
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, prices, 1, dp);
    }
};