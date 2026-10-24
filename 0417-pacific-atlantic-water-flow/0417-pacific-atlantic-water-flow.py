class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        ROWS = len(heights)
        COLS = len(heights[0])

        pacific = set()
        atlantic = set()


        def dfs(r, c, ocean, prevHeight):
            if r not in range(ROWS) or c not in range(COLS) or heights[r][c] < prevHeight or (r, c) in ocean:
                return
            
            ocean.add((r, c))
            dfs(r + 1, c, ocean, heights[r][c])
            dfs(r - 1, c, ocean, heights[r][c])
            dfs(r, c + 1, ocean, heights[r][c])
            dfs(r, c - 1, ocean, heights[r][c])
        
        for i in range(ROWS):
            dfs(i, 0, pacific, heights[i][0])
            dfs(i, COLS - 1, atlantic, heights[i][COLS - 1])
        
        for j in range(COLS):
            dfs(0, j, pacific, heights[0][j])
            dfs(ROWS - 1, j, atlantic, heights[ROWS - 1][j])

        result = []
        for i in range(ROWS):
            for j in range(COLS):
                if (i, j) in pacific and (i, j) in atlantic:
                    result.append([i, j])
        
        return result
        
