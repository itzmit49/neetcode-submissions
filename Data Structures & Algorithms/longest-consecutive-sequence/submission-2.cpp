class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1;

        for (auto num : st) {
            if (!st.count(num - 1)) {
                int len = 1;
                int curr = num;
                while (st.count(curr + 1)) {
                    len++;
                    curr++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};
