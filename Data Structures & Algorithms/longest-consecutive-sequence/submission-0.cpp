class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for (auto num : nums) {
            int streak = 0, curr = num;
            while (st.find(curr) != st.end()) {
                streak++;
                curr++;
            }
            res = max(res, streak);
        }
        return res;
    }
};
