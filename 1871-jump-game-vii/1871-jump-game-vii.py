class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        q = deque([0])
        farthest = 0

        n = len(s)
        if s[n - 1] == "1":
            return False
        
        while q:
            i = q.popleft()
            start = max(i + minJump, farthest + 1)
            end = min(i + maxJump, n - 1)

            for j in range(start, end + 1):
                if s[j] == "0":
                    q.append(j)

                    if j == n - 1:
                        return True
            
            farthest = max(farthest, end)
        
        return False
