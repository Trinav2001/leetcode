class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()

        median = nums[len(nums) // 2]

        steps = 0

        for num in nums:
            steps += abs(median - num)
        
        return steps