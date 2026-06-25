class Solution {
public:

    bool isRow(int r, char c, vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {
            if (board[r][j] == c) return false;
        }
        return true;
    }

    bool isCol(int cIdx, char c, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][cIdx] == c) return false;
        }
        return true;
    }

    bool isBox(int r, int c, char ch, vector<vector<char>>& board) {
        int boxRow = (r / 3) * 3;
        int boxCol = (c / 3) * 3;

        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == ch) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    char ch = board[i][j];

                   
                    board[i][j] = '.';  

                    if (!isRow(i, ch, board) ||
                        !isCol(j, ch, board) ||
                        !isBox(i, j, ch, board)) {
                        return false;
                    }

                    board[i][j] = ch;
                }
            }
        }
        return true;
    }
};