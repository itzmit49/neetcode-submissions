class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int nu:nums)mp[nu]++;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]--;
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++){
                mp[nums[j]]--;
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int tar=-(nums[i]+nums[j]);
                if(mp[tar]>0){
                    ans.push_back({nums[i],nums[j],tar});
                }
            }
            for(int j=i+1;j<nums.size();j++){
                mp[nums[j]]++;
            }
        }
        
return ans;
        
    }
};
