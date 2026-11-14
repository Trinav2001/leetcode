class Solution:
    def reverse(self, x: int) -> int:
        reversedInteger = 0
        num = abs(x)
        
        while num != 0:
            reversedInteger = reversedInteger * 10 + num % 10
            num //= 10
        
        if x < 0:
            reversedInteger *= -1
        
        if reversedInteger < -(2**31) or reversedInteger > 2**31 - 1:
            return 0
            
        return reversedInteger
        
        
        