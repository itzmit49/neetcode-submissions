class Solution {
public:
    bool dfs(int st, int tar, vector<vector<int>>& adj, vector<int>& vis) {

        if(st == tar)
            return true;

        vis[st] = 1;

        for(auto it : adj[st]) {
            if(!vis[it]) {
                if(dfs(it, tar, adj, vis))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for(auto &it : edges) {

            vector<int> vis(n + 1, 0);

            if(dfs(it[0], it[1], adj, vis))
                return it;

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return {};
    }
};