class Solution {
public:
int ROWS, COLS;
int maxArea;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
        
    }


    int dfs (vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        return 1 + dfs (grid, r + 1, c) + dfs (grid, r - 1, c) 
        + dfs (grid, r, c + 1) + dfs (grid, r, c - 1);
    }
};