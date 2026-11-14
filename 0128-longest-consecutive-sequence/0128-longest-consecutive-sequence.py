class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        maxLength = 0
        s = set(nums)

        for num in s:
            if num - 1 in s:
                continue

            length = 1
            cur = num
            while cur + 1 in s:
                length += 1
                cur += 1
            
            maxLength = max(maxLength, length)
        
        return maxLength
        