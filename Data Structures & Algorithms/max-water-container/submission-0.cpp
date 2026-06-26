class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int water = 0;

        while (l < r) {
            int h = min(heights[l], heights[r]);

            int w = r - l;

            water = max(water, h * w);

            if (heights[l] > heights[r])
                r--;
            else
                l++;
        }

        return water;
    }
};