class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        maxArea = 0


        def dfs(r, c):
            if r not in range(ROWS) or c not in range(COLS) or grid[r][c] == 0:
                return 0
            
            grid[r][c] = 0
            return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1)
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    area = dfs(i, j)
                    maxArea = max(maxArea, area)

        return maxArea
        