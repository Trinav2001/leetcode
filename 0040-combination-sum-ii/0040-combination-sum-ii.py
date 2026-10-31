class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:

        subset = []
        output = []
        candidates.sort()

        def dfs(i, total):
            if total == target:
                output.append(subset.copy())
                return
            
            if i >= len(candidates) or total > target:
                return
            
            subset.append(candidates[i])
            dfs(i + 1, total + candidates[i])

            subset.pop()
            while i + 1 < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1

            dfs(i + 1, total)

        
        dfs(0, 0)
        return output
        