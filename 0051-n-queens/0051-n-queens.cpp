class Solution {
private:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> negDiag;
    unordered_set<int> posDiag;

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(n, board, 0);
        
        return res;
    }

    void backtrack(int n, vector<string>& board, int r) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || negDiag.count(r - c) || posDiag.count(r + c)) {
                continue;
            }

            board[r][c] = 'Q';
            cols.insert(c);
            negDiag.insert(r - c);
            posDiag.insert(r + c);

            backtrack(n, board, r + 1);

            cols.erase(c);
            negDiag.erase(r - c);
            posDiag.erase(r + c);
            board[r][c] = '.';
        }
    }

    
};