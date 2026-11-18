class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        stack = []
        nextGreater = {}
        ans = []

        for num in nums2:
            while stack and num > stack[-1]:
                key = stack.pop()
                nextGreater[key] = num
            
            stack.append(num)
        
        while stack:
            key = stack.pop()
            nextGreater[key] = -1
        
        for num in nums1:
            ans.append(nextGreater[num])
        
        return ans

        