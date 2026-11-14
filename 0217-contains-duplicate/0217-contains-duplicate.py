class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set(nums)
        return len(nums) != len(seen)