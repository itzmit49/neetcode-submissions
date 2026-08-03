class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
         vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        dist[0][0]=grid[0][0];
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int time=curr[0];
            int  i=curr[1];
            int j=curr[2];
            if(i==m-1&&j==n-1)return time;
            if(time>dist[i][j])continue;
            for(auto it:dir){
                int ni=i+it.first;
                int nj=j+it.second;
                if(ni<0||nj<0||ni>=m||nj>=n)continue;
                int newtime=max(time,grid[ni][nj]);
                if(newtime<dist[ni][nj]){
                    dist[ni][nj]=newtime;
                    pq.push({newtime,ni,nj});
                }

            }
        }
        return -1;
        
    }
};
