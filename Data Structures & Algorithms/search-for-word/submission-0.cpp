class Solution {
public:
    bool solve(int i,int j,int idx,int m,int n,vector<vector<char>>& board, string word){
        if(idx==word.size())return true;

        if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[idx]||board[i][j]=='!')return false;

        char c=board[i][j];
        board[i][j]='!';
         bool top = solve(i-1, j, idx+1, m, n, board, word);
        bool down = solve(i+1, j, idx+1, m, n, board, word);
        bool left = solve(i, j-1, idx+1, m, n, board, word);
        bool right = solve(i, j+1, idx+1, m, n, board, word);

        board[i][j] = c;

        return top || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,0,m,n,board,word))return true;
                }

            }
        }
        return false;
    }
};
