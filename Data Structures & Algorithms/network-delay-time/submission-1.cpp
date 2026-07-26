class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for (auto &adjNode : adj[node]) {
                if (time + adjNode.second < dist[adjNode.first]) {
                    dist[adjNode.first] = time + adjNode.second;
                    pq.push({dist[adjNode.first], adjNode.first});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};