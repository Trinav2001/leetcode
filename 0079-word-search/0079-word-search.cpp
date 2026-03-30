class Solution {
private:
    vector<vector<bool>> visited;
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
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

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i) {

        if (i == word.length()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i] || visited[r][c]) {
            return false;
        }

        visited[r][c] = true;
        bool res = false;
        for (int k = 0; k < 4; k++) {
            int x = r + directions[k][0];
            int y = c + directions[k][1];
            res = res || backtrack(board, word, x, y, i + 1);
        }
        visited[r][c] = false;

        return res;
    }
};