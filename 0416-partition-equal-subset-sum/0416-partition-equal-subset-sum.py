class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        
        total = sum(nums)
        if total % 2:
            return False
        
        target = total // 2
        
        seen = set()
        seen.add(0)

        for i in range(len(nums) - 1, -1, -1):
            nextDP = set()
            for n in seen:
                if n + nums[i] == target:
                    return True
                nextDP.add(n)
                nextDP.add(n + nums[i])
            seen = nextDP

        return target in seen
        