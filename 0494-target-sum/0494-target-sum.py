class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        dp = {}
        def dfs(i, curSum):
            if i == len(nums):
                return curSum == target
            
            if (i, curSum) in dp:
                return dp[(i, curSum)]
            
            dp[(i, curSum)] = dfs(i + 1, curSum + nums[i]) + dfs(i + 1, curSum - nums[i])
            return dp[(i, curSum)]
        
        return dfs(0, 0)
        