class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        pq = []

        for stone in stones:
            heapq.heappush(pq, -stone)
        
        while len(pq) > 1:
            a = -heapq.heappop(pq)
            b = -heapq.heappop(pq)
            if a != b:
                heapq.heappush(pq, -(a - b))
        
        return -pq[0] if pq else 0
        