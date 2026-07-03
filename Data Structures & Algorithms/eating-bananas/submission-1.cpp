class Solution {
public:
    bool caneat(int k,vector<int>& piles, int h){
        long long  need=0;
        for(auto it:piles){
            need+=ceil((double)it/k);
            if(need>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=right;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(caneat(mid,piles,h)){
                ans=mid;
                right=mid-1;

            }else left=mid+1;
        }
        return ans;
    }
};
