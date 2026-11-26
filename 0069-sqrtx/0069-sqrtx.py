class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        
        l, r = 0, x // 2
        res = -1

        while l <= r:
            m = l + (r - l) // 2

            if (m * m <= x):
                res = m
                l = m + 1
            
            else:
                r = m - 1
        
        return res
        