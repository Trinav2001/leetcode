class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        l, r = 0, n - 1

        leftMax, rightMax = height[l], height[r]

        output = 0

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
        