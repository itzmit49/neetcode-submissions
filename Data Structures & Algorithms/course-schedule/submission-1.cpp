class Solution {
public:
    bool dfs(int node,int n,vector<int>&vis,vector<vector<int>>&adj){
       vis[node]=1;
       for(auto adjnode:adj[node]){
        if(!vis[adjnode]){
            if(dfs(adjnode,n,vis,adj))return true;
        }
        else if(vis[adjnode]==1)return true;
       }
       vis[node]=2;
       return false;

    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(auto it:p){
            adj[it[0]].push_back(it[1]);

        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        if(dfs(i,n,vis,adj))return false;
        return true;

    }
};
