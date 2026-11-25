class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        
        output = []

        def backtrack(openBrackets, closeBrackets, subset):
            if openBrackets == n and closeBrackets == n:
                output.append(subset)
            
            if openBrackets < n:
                backtrack(openBrackets + 1, closeBrackets, subset + '(')
            
            if closeBrackets < openBrackets:
                backtrack(openBrackets, closeBrackets + 1, subset + ')')
                            

        backtrack(0, 0, "")
        return output
        