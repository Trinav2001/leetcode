class Solution:
    def letterCombinations(self, digits: str) -> list[str]:

        digitsToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        output = []

        def dfs(i, curStr):
            if len(curStr) == len(digits):
                output.append(curStr)
                return
            
            for c in digitsToChar[digits[i]]:
                dfs(i + 1, curStr + c)
                

        dfs(0, "")
        return output
        