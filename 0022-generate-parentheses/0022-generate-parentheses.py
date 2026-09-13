class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.n = n

        openBrackets = 0
        closeBrackets = 0

        self.DFS("", openBrackets, closeBrackets)
        return self.res

    def DFS(self, substr, openBrackets, closeBrackets):
        if openBrackets == self.n and closeBrackets == self.n:
            self.res.append(substr)
            return
            
        if openBrackets < self.n:
            openBrackets += 1
            self.DFS(substr + '(', openBrackets, closeBrackets)
            openBrackets -= 1
            
        if closeBrackets < openBrackets:
            closeBrackets += 1
            self.DFS(substr + ')', openBrackets, closeBrackets)
            closeBrackets -= 1

            




        