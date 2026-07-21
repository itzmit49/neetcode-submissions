class Solution {
public:
    int m, n;

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        queue<pair<int,int>> q;

        // Top and Bottom rows
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') q.push({0, j});
            if(board[m-1][j] == 'O') q.push({m-1, j});
        }

        // Left and Right columns
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {

            auto [x,y] = q.front();
            q.pop();

            if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O')
                continue;

            board[x][y] = 'S';

            for(auto d : dir) {
                q.push({x + d.first, y + d.second});
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};