class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> columns;
        unordered_map<string, unordered_set<char>> squares;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                string key = to_string(i/3) + ", " + to_string(j/3);
                if(rows[i].count(board[i][j]) || columns[j].count(board[i][j]) || squares[key].count(board[i][j])) {
                    return false;
                }

                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                squares[key].insert(board[i][j]);

            }
        }
        return true;
    }
};