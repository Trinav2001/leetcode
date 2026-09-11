class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        pq = []
        output = []

        for x, y in points:
            dist = x ** 2 + y ** 2
            heapq.heappush(pq, [dist, x, y])
        
        while k > 0:
            dist, x, y = heapq.heappop(pq)
            output.append([x, y])
            k -= 1
        
        return output


        