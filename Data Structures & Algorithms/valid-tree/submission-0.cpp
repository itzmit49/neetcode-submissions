class Solution {
public:
    void dfs(int node, int &ct, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        ct++;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, ct, vis, adj);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ct = 0;
        dfs(0, ct, vis, adj);

        return ct == n;
    }
};