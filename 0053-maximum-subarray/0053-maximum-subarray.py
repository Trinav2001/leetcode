class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        curSum = float("-infinity")
        maxSub = float("-infinity")

        for num in nums:
            if curSum < 0:
                curSum = 0
            curSum += num
            maxSub = max(maxSub, curSum)
        
        return maxSub
        