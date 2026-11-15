class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        res = ""

        for i in range(numRows):
            inc = 2 * (numRows - 1) 

            for j in range(i, len(s), inc):
                res += s[j]

                if (i > 0  and i < numRows - 1 and j + inc - 2 * i < len(s)):
                    res += s[j + inc - 2 * i]
        
        return res


        