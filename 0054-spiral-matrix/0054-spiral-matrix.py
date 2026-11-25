class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        output = []
        top, left = 0, 0
        bottom, right = len(matrix), len(matrix[0])

        while left < right and top < bottom:
            for i in range(left, right):
                output.append(matrix[top][i])
            top += 1

            for j in range(top, bottom):
                output.append(matrix[j][right - 1])
            right -= 1

            if not (left < right and top < bottom):
                break
            
            for i in range(right - 1, left - 1, -1):
                output.append(matrix[bottom - 1][i])
            bottom -= 1

            for j in range(bottom - 1, top - 1, -1):
                output.append(matrix[j][left])
            left += 1
        
        return output


        