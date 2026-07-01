class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        for (int i = 0; i + k <= nums.size(); i++) {
            int mx = nums[i];

            for (int j = i; j < i + k; j++) {
                mx = max(mx, nums[j]);
            }

            ans.push_back(mx);
        }

        return ans;
    }
};