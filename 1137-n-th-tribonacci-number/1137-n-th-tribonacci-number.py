class Solution:
    def tribonacci(self, n: int) -> int:
        if n <= 1:
            return n
        
        if n == 2:
            return 1
        
        firstPrev = 1
        secondPrev = 1
        thirdPrev = 0

        for i in range(n - 2):
            tmp = firstPrev
            firstPrev += (secondPrev + thirdPrev)
            thirdPrev = secondPrev
            secondPrev = tmp
        
        return firstPrev
            
            
            

        