class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        subset = []
        output = []

        def dfs():
            if len(subset) == len(nums):
                output.append(subset.copy())
                return
            
            for num in nums:
                if num in subset:
                    continue
                
                subset.append(num)
                dfs()
                subset.pop()
        
        dfs()
        return output
        