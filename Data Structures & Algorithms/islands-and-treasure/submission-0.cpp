class Solution {
public:
    void dfs(int i, int j, int dist, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] < dist)
            return;

        grid[i][j] = dist;

        dfs(i + 1, j, dist + 1, grid);
        dfs(i - 1, j, dist + 1, grid);
        dfs(i, j + 1, dist + 1, grid);
        dfs(i, j - 1, dist + 1, grid);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, 0, grid);
                }
            }
        }
    }
};