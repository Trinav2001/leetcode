class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        output = [0] * len(temperatures)
        stack = []

        for i in range(len(temperatures)):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                idx = stack.pop()
                output[idx] = i - idx
            
            stack.append(i)
        
        return output

        