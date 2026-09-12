class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:

        count = Counter(tasks)  # creates a map with count of each variable in tasks
        maxHeap = []
        for cnt in count.values():
            maxHeap.append(-cnt)
        
        heapq.heapify(maxHeap)
        q = deque()
        time = 0
        while maxHeap or q:
            time += 1
            if maxHeap:
                cnt = 1 + heapq.heappop(maxHeap)
                if cnt:
                    q.append((cnt, time + n))
            
            if q and q[0][1] == time:
                freq = q.popleft()[0]
                heapq.heappush(maxHeap, freq)
            

        return time






        
