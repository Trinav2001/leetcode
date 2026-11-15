class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        maxStreak = 0
        streak = 0

        for i in range(len(nums)):
            if nums[i] == 1:
                streak += 1
            else:
                streak = 0
            
            maxStreak = max(maxStreak, streak)
        
        return maxStreak

        