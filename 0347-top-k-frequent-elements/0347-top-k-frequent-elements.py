import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Priority Queue
        # count = {}

        # for num in nums:
        #     count[num] = count.get(num, 0) + 1

        # heap = []

        # for key in count:
        #     heapq.heappush(heap, (-count[key], key))

        # ans = []

        # while k > 0:
        #     ans.append(heapq.heappop(heap)[1])
        #     k -= 1
        
        # return ans


        # Bucket Sort
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        
        bucket = [[] for _ in range(len(nums) + 1)]

        for key, freq in count.items():
            bucket[freq].append(key)

        ans = []    
        for freq in range(len(bucket) - 1, 0, -1):
            for num in bucket[freq]:
                ans.append(num)

                if len(ans) == k:
                    return ans

        