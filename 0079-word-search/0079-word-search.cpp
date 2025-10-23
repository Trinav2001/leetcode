class Solution {
public:
int rows, cols;
vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack (vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.length()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
        board[r][c] != word[i] || visited[r][c]) {
            return false;
        }

        visited[r][c] = true;
        bool res = backtrack(board, word, r + 1, c, i + 1) ||
            backtrack(board, word, r, c + 1, i + 1) ||
            backtrack(board, word, r - 1, c, i + 1) ||
            backtrack(board, word, r, c - 1, i + 1);

        visited[r][c] = false;

        return res;

    }
};