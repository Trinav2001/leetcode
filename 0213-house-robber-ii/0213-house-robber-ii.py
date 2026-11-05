class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
            
        def robRange(start, end):
            prev1 = 0
            prev2 = 0
            for i in range(start, end + 1):
                current = max(prev1, prev2 + nums[i])
                prev2 = prev1
                prev1 = current
            
            return prev1
            
        
        return max(robRange(0, n - 2), robRange(1, n - 1))
        