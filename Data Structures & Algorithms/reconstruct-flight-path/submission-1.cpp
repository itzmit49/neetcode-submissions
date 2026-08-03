class Solution {
public:
    unordered_map<string, priority_queue<string,vector<string>,greater<string>>>adj;
    vector<string>ans;
    void dfs(const string&src){
        while(!adj[src].empty()){
            string nxt=adj[src].top();
            adj[src].pop();
            dfs(nxt);

        }
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it:tickets){
            adj[it[0]].push(it[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};