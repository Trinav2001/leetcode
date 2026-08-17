class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [set() for _ in range(9)]
        column = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(0, 9):
            for j in range(0, 9):
                val = board[i][j]
                if val == ".":
                    continue
                
                if val in row[i]:
                    return False
                
                if val in column[j]:
                    return False

                box = (i // 3) * 3 + (j // 3)

                if val in boxes[box]:
                    return False
                
                row[i].add(val)
                column[j].add(val)
                boxes[box].add(val)
            
        return True
                
        