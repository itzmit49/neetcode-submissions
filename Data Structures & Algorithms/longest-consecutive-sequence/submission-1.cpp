class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int res=1;
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
             if(nums[i]==nums[i-1]+1){
                cnt++;
            }else {
                cnt=1;

            }
            res=max(res,cnt);
        }
       return res;
    }
};
