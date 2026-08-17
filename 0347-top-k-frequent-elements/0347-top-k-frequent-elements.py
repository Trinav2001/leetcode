import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}

        for num in nums:
            count[num] = count.get(num, 0) + 1

        heap = []

        for key in count:
            heapq.heappush(heap, (-count[key], key))

        ans = []

        while k > 0:
            ans.append(heapq.heappop(heap)[1])
            k -= 1
        
        return ans

        