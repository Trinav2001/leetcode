class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        dp = defaultdict(int)
        dp[0] = 1

        for i in range(len(nums)):
            nextDp = defaultdict(int)
            for total, count in dp.items():
                nextDp[total - nums[i]] += count
                nextDp[total + nums[i]] += count
            
            dp = nextDp
        
        return dp[target]
        