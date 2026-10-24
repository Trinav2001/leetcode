class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        fresh = 0
        time = 0

        q = deque()

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 2:
                    q.append((i, j))
                
                elif grid[i][j] == 1:
                    fresh += 1
        
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while fresh > 0 and q:
            length = len(q)

            while length:
                r, c = q.popleft()
                for dr, dc in directions:
                    row = r + dr
                    col = c + dc
                    
                    if row not in range(ROWS) or col not in range(COLS):
                        continue

                    if grid[row][col] == 1:
                        fresh -= 1
                        grid[row][col] = 2
                        q.append((row, col))
                
                length -= 1
            
            time += 1

        return time if fresh == 0 else -1
        