class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maxStreak = 0
        s = set()

        for num in nums:
            s.add(num)

        for num in s:
            # Only start counting when num is the start of a sequence
            if num - 1 in s:
                continue
            
            curStreak = 1
            curNum = num

            while curNum + 1 in s:
                curStreak += 1
                curNum = curNum + 1
            
            maxStreak = max(maxStreak, curStreak)
            
        
        return maxStreak
        