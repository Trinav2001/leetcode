class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:

        r = max(piles)
        l = 1

        while l <= r:
            m = l + (r - l) // 2
            time = 0
            for pile in piles:
                time += math.ceil(pile / m)
            
            if time > h:
                l = m + 1
            
            elif time <= h:
                r = m - 1

        return l
            
            

        