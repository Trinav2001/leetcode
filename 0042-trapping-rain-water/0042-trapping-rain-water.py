class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        output = 0

        if n == 0:
            return output
        
        l = 0
        r = n - 1
        leftMax = height[l]
        rightMax = height[r]
        
        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                output += leftMax - height[l]
            
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                output += rightMax - height[r]
        
        return output
        