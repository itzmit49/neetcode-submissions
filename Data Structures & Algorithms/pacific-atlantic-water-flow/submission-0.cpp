class Solution {
public:
    bool p, a;
    int m, n;

    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i, int j, vector<vector<int>>& h, vector<vector<bool>>& vis) {

    if(vis[i][j]) return;

    vis[i][j] = true;

    for(auto d : dir){

        int ni = i + d.first;
        int nj = j + d.second;

        if(ni >= 0 && ni < m &&
           nj >= 0 && nj < n &&
           !vis[ni][nj] &&
           h[ni][nj] >= h[i][j]){

            dfs(ni, nj, h, vis);
        }
    }
}

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {

        m = h.size();
        n = h[0].size();
        vector<vector<bool>>P(m,vector<bool>(n,false));
          vector<vector<bool>>A(m,vector<bool>(n,false));
          
for(int j = 0; j < n; j++) dfs(0, j, h, P);
for(int i = 0; i < m; i++) dfs(i, 0, h, P);


for(int j = 0; j < n; j++) dfs(m - 1, j, h, A);
for(int i = 0; i < m; i++) dfs(i, n - 1, h, A);


        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                
                //vector<vector<bool>> vis(m, vector<bool>(n, false));

                

                if (P[i][j]&& A[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};