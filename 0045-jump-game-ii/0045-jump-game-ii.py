class Solution:
    def jump(self, nums: list[int]) -> int:
        res = 0
        l, r = 0, 0

        while r < len(nums) - 1:
            farthest = r
            for i in range(l, r + 1):
                farthest = max(farthest, i + nums[i])
            l, r = r + 1, farthest
            res += 1
        
        return res
        