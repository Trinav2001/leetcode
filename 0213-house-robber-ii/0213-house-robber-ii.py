class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
            
        def robRange(start, end):

            memo = [-1] * len(nums)

            def dfs(i):
                if i > end:
                    return 0
                
                if memo[i] != -1:
                    return memo[i]
                
                rob = nums[i] + dfs(i + 2)
                skip = dfs(i + 1)

                memo[i] = max(rob, skip)
                return memo[i]
            
            return dfs(start)
        
        return max(robRange(0, n - 2), robRange(1, n - 1))
        