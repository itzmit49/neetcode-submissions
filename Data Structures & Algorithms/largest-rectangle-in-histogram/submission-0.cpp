class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {

            int h = heights[i];

            int right = i + 1;

            while(right < heights.size() &&
                  heights[right] >= h) {
                right++;
            }

            int left = i - 1;

            while(left >= 0 &&
                  heights[left] >= h) {
                left--;
            }

            int width = right - left - 1;

            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};