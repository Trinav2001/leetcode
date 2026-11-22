class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:

        def canSplit(largest):

            subArray = 1
            curSum = 0

            for num in nums:
                curSum += num
                if curSum > largest:
                    curSum = num
                    subArray += 1
            
            return subArray <= k

        l, r = max(nums), sum(nums)
        res = r

        while l <= r:
            m = l + (r - l) // 2
            if canSplit(m):
                res = m
                r = m - 1
            
            else:
                l = m + 1
        
        return res
        
        
        
        