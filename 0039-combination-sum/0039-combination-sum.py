class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        subset = []
        output = []

        def dfs(i, total):
            if total == target:
                output.append(subset.copy())
                return
            
            if i >= len(candidates) or total > target:
                return
            
            subset.append(candidates[i])
            dfs(i, total + candidates[i])

            subset.pop()
            dfs(i + 1, total)
        
        dfs(0, 0)
        return output