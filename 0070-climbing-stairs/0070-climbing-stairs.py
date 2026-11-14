class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        firstPrev, secondPrev = 2, 1 
        for i in range(3, n + 1):
            firstPrev, secondPrev = firstPrev + secondPrev, firstPrev
        
        return firstPrev


        