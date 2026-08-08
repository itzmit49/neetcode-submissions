class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int st=intervals[i][0];
            int ed=intervals[i][1];
            if(ans.back()[1]>=st){
                ans.back()[1]=max(ans.back()[1],ed);
            }else ans.push_back(intervals[i]);
        }
        return ans;
        
    }
};
