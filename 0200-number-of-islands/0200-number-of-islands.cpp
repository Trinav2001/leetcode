class Solution {
public:

int ROWS, COLS;
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
    
    int numIslands(vector<vector<char>>& grid) {
    
        int islands = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
        
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        for (int i = 0; i < directions.size(); i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    }
};