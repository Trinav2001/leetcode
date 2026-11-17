class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        output = [[1]]

        for i in range(numRows - 1):
            row = [1]
            prev = output[-1]

            for j in range(len(prev) - 1):
                row.append(prev[j] + prev[j + 1])
            
            row.append(1)
            output.append(row)
        
        return output
            
            

        