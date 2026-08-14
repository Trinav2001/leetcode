class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # s = set(nums)
        # return len(s) != len(nums)

        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        
        return False



        