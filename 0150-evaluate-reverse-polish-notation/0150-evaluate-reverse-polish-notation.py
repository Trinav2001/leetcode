class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t == "-":
                x = stack.pop()
                y = stack.pop()
                z = y - x
                stack.append(z)

            elif t == "+":
                x = stack.pop()
                y = stack.pop()
                z = x + y
                stack.append(z)

            elif t == "*":
                x = stack.pop()
                y = stack.pop()
                z = x * y
                stack.append(z)

            elif t == "/":
                x = stack.pop()
                y = stack.pop()
                z = int(y / x)
                stack.append(z)
            
            else:
                stack.append(int(t))
        
        return stack[-1]

            
         