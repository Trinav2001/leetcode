class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        dq = deque()
        n = len(nums)
        l = 0
        r = 0
        output = []

        while r < n:
            while dq and nums[r] > nums[dq[-1]]:
                dq.pop()
            
            dq.append(r)

            if l > dq[0]:
                dq.popleft()

            if r - l + 1 == k:
                output.append(nums[dq[0]])
                l += 1
            
            r += 1

        return output