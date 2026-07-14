class Solution {
public:
vector<vector<int>>ans;
    void solve(int idx,vector<int>&nums,int tar,int sum,vector<int>temp){
         if(sum==tar){
            ans.push_back(temp);
            return;
          }
         
          if(idx>=nums.size()||sum>tar){
           
            return;
          }
         
          temp.push_back(nums[idx]);
            solve(idx,nums,tar,sum+nums[idx],temp);
             temp.pop_back();
          solve(idx+1,nums,tar,sum,temp);
          
         

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        solve(0,nums,target,0,{});
        return ans;


        
    }
};
