class Solution {
public:
bool isSafe(int row, int col, int n, vector<string>& board) {

    // Check left
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 'Q')
            return false;
    }

    // Upper-left diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }

    // Lower-left diagonal
    i = row;
    j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 'Q')
            return false;
        i++;
        j--;
    }

    return true;
}

   void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(i,col,n,board)){
            board[i][col]='Q';
            solve(col+1,n,board,ans);
            board[i][col]='.';
        }
    }

   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board(n, string(n, '.'));
        solve(0,n,board,ans);
        return ans;

    }
};
