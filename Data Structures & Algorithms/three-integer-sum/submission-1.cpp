class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int tar = -(nums[i] + nums[j]);

                int left = j + 1;
                int right = n - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (nums[mid] == tar) {
                        ans.push_back({nums[i], nums[j], tar});
                        break;
                    }

                    else if (nums[mid] > tar)
                        right = mid - 1;

                    else
                        left = mid + 1;
                }
            }
        }

        return ans;
    }
};