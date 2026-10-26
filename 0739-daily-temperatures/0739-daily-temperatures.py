class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        
        size = len(temperatures)

        output = [0] * size
        stack = []

        for i in range(size):
            
            while stack and temperatures[i] > stack[-1][0]:
                temp, idx = stack.pop()
                output[idx] = i - idx

            stack.append((temperatures[i], i))
        
        return output
        