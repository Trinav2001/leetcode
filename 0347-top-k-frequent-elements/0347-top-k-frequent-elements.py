class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        count = defaultdict(int)

        for num in nums:
            count[num] += 1
        
        pq = []

        for key, val in count.items():
            heapq.heappush(pq, (val, key))

            if len(pq) > k:
                heapq.heappop(pq)
            
        return [key for val, key in pq]