class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int minpro=1;
        int maxpro=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)swap(minpro,maxpro);
            maxpro=max(nums[i],maxpro*nums[i]);
            minpro=min(nums[i],minpro*nums[i]);
            ans=max(ans,maxpro);
          
            
            
        }
        return ans;
    }
};
