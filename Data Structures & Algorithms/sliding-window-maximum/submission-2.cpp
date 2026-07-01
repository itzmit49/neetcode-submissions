class Solution {
public:
    
    int findMax(vector<int>& nums, int l, int r,vector<int>&dp) {
        if (l == r) return nums[l];
        if(dp[l]!=-1)return dp[l];

        return dp[l]= max(nums[l], findMax(nums, l + 1, r,dp));
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;


        for (int i = 0; i + k <= nums.size(); i++) {
            vector<int>dp(nums.size(),-1);
            ans.push_back(findMax(nums, i, i + k - 1,dp));
        }

        return ans;
    }
};