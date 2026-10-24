class Solution:
    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        ROWS = len(board)
        COLS = len(board[0])

        def dfs(r, c):
            if r not in range(ROWS) or c not in range(COLS) or board[r][c] != "O":
                return
            
            board[r][c] = "*"
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)
                    

        for i in range(ROWS):
            dfs(i, 0)
            dfs(i, COLS - 1)
        
        for j in range(COLS):
            dfs(0, j)
            dfs(ROWS - 1, j)

        for i in range(ROWS):
            for j in range(COLS):
                if board[i][j] == "*":
                    board[i][j] = "O"
                
                elif board[i][j] == "O":
                    board[i][j] = "X"
        
        
    
        
        
