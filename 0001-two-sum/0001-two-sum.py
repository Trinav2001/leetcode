class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}

        for i in range(len(nums)):
            diff = target - nums[i]

            if diff in mp:
                return [i, mp[diff]]
            
            mp[nums[i]] = i

        