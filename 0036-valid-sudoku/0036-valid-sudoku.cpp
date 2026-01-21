class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> columns;
        unordered_map<string, unordered_set<int>> square;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                string key = to_string(i/3) + ", " + to_string(j/3);

                if (rows[i].count(board[i][j]) || columns[j].count(board[i][j]) ||
                square[key].count(board[i][j])) {
                    return false;
                }

                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                square[key].insert(board[i][j]);
            }
        }

        return true;


        
    }
};