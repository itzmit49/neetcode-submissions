class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (idx >= n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

      for (int jump = 1; jump <= nums[idx] && idx + jump < nums.size(); jump++) {
    int temp = solve(idx + jump, nums, dp);

    if (temp != INT_MAX)
        ans = min(ans, 1 + temp);
}

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};