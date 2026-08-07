class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int currsum=0;
        for(auto it:nums){
            if(currsum<0)currsum=0;
            currsum+=it;
            ans=max(ans,currsum);
        }
return ans;

    }
};
