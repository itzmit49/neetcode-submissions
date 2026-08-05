class Solution {
public:
    const int INF = 1e9;
   vector<vector<int>>dp;

    int solve(int idx, vector<int>& coins, int tar) {
        if (tar == 0)
            return 0;

        if (idx == coins.size())
            return INF;
          if(dp[idx][tar]!=-1)return dp[idx][tar];

        int take = INF;
        if (coins[idx] <= tar)
            take = 1 + solve(idx, coins, tar - coins[idx]);

        int notTake = solve(idx + 1, coins, tar);

        return dp[idx][tar]= min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       dp.assign(n, vector<int>(amount + 1, -1));
        int ans = solve(0, coins, amount);

        return (ans == INF) ? -1 : ans;
    }
};