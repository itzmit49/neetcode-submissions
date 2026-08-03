class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        int connect=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        pq.push({0,0});
        while(connect<n){
            auto [wt,node]=pq.top();
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            ans+=wt;
            connect++;
            for(int i=0;i<n;i++){
              if(!vis[i]) { int d=abs(points[node][0]-points[i][0])+
                        abs(points[node][1]-points[i][1]);
                        pq.push({d,i});
}
                            }
        }

        return ans;
    }
};
