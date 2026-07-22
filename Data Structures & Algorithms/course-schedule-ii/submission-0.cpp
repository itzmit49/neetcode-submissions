class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &it : p) {
            adj[it[1]].push_back(it[0]); 
            indegree[it[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if (ans.size() != n)
            return {};

        return ans;
    }
};