class Solution:
    def canMakeArithmeticProgression(self, arr: list[int]) -> bool:
        s = set(arr)

        mx = max(arr)
        mn = min(arr)
        n = len(arr)

        if (mx - mn) % (n - 1) != 0:
            return False

        diff = (mx - mn) // (n - 1)

        if diff == 0:
            return True
        
        for i in range(n):
            expected = mn + i * diff

            if expected not in s:
                return False

        
        return True
        
        
        