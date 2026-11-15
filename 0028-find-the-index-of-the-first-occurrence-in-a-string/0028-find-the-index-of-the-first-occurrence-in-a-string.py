class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) > len(haystack):
            return -1

        for k in range(len(haystack) - len(needle) + 1):
            
            if haystack[k : k + len(needle)] == needle:
                return k
        
        return -1
        