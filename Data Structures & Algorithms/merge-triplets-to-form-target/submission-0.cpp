class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>temp(3,-1);
        for(int i=0;i<triplets.size();i++){
            vector<int>curr=triplets[i];
            if(curr[0]>target[0]||curr[1]>target[1]||curr[2]>target[2])continue;
            temp[0]=max(temp[0],curr[0]);
            temp[1]=max(temp[1],curr[1]);
            temp[2]=max(temp[2],curr[2]);

        }

        
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=target[i])return false;
        }
        return true;


        
    }
};