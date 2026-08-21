class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        mp = {
            ')': '(',
            '}': '{',
            ']': '['
        }


        for c in s:
            if c == '(' or c == '{' or c == '[':
                 stack.append(c)

            elif stack and mp[c] == stack[-1]:
                stack.pop()
            
            else:
                return False
        
        return not stack

           
        