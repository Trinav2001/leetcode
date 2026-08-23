class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        maxPile = max(piles)
        total = sum(piles)
        l = 1
        r = maxPile

        while l <= r:
            m = l + (r - l) // 2
            time = 0
            for pile in piles:
                time += math.ceil(pile / m)

            if time <= h:
                r = m - 1
            
            elif time > h:
                l = m + 1
        
        return l


        