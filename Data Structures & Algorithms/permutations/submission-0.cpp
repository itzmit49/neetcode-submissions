class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>temp,vector<int>&vis){
      if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
      }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(nums,temp,vis);

                vis[i]=0;
                temp.pop_back();
               // solve(nums,temp,vis);
                

            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,0);
        solve(nums,{},vis);

        return ans;
        
    }
};
