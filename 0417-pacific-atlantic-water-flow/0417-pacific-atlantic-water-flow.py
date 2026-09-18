class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:

        ROWS = len(heights)
        COLS = len(heights[0])
        pacific = set()
        atlantic = set()

        def dfs(r, c, pacific, prevHeight):
            if r not in range(ROWS) or c not in range(COLS) or heights[r][c] < prevHeight or (r, c) in pacific:
                return
            
            pacific.add((r, c))
            dfs(r + 1, c, pacific, heights[r][c])
            dfs(r - 1, c, pacific, heights[r][c])
            dfs(r, c + 1, pacific, heights[r][c])
            dfs(r, c - 1, pacific, heights[r][c])


        for r in range(ROWS):
            dfs(r, 0, pacific, heights[r][0])
            dfs(r, COLS - 1, atlantic, heights[r][COLS - 1])
        
        for c in range(COLS):
            dfs(0, c, pacific, heights[0][c])
            dfs(ROWS - 1, c, atlantic, heights[ROWS - 1][c])
        
        res = []

        for r in range(ROWS):
            for c in range(COLS):
                if (r, c) in pacific and (r, c) in atlantic:
                    res.append([r, c])
        
        return res

        