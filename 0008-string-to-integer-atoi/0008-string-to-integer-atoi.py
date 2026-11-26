class Solution:
    def myAtoi(self, s: str) -> int:
        sign = 1
        i = 0

        while i < len(s) and s[i] == " ":
            i += 1
        
        if i == len(s):
            return 0
        
        if s[i] == '-':
            sign = -1
            i += 1
        
        elif s[i] == '+':
            i += 1
        
        num = 0

        while i < len(s) and s[i].isdigit():
            digit = ord(s[i]) - ord('0')
            num = num * 10 + digit
            i += 1
        
        num *= sign

        if num < -(2**31):
            return -(2**31)
        
        if num > (2**31) - 1:
            return 2**31 - 1
        
        return num
        

        