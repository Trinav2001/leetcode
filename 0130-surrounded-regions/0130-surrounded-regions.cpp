class Solution {
public:
int ROWS, COLS;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < ROWS; i++) {
            dfs (board, i, 0);
            dfs (board, i, COLS - 1);
        }
        for (int i = 0; i < COLS; i++) {
            dfs (board, 0, i);
            dfs (board, ROWS - 1, i);
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        
    }

    void dfs (vector<vector<char>>& board, int r, int c) {
        
        if (board[r][c] != 'O') return;

        board[r][c] = '*';

        for (int i = 0; i < 4; i++) {
            int x = r + directions[i][0];
            int y = c + directions[i][1];

            if (x >= 0 && x < ROWS && y >= 0 && y < COLS && board[x][y] == 'O') {
                dfs (board, x, y);
            }
        }
    }
};