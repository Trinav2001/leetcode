class Solution:
    def combinationSum4(self, nums: list[int], target: int) -> int:
        nums.sort()
        cache = { 0 : 1 }

        def dfs(curSum):
            if curSum == 0:
                return 1

            if curSum in cache:
                return cache[curSum]

            res = 0
            for n in nums:
                if curSum < n:
                    break
                
                res += dfs(curSum - n)

            cache[curSum] = res
            return res
        
        return dfs(target)
        