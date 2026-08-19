class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        size = len(nums)
        nums.sort()
        output = []
        for i in range(0, size):

            if nums[i] > 0:
                break
                
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            l = i + 1
            r = size - 1

            while l < r:

                total = nums[i] + nums[l] + nums[r]
                if total < 0:
                    l += 1
                
                elif total > 0:
                    r -= 1
                
                else:
                    output.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    
                    l += 1
                    r -= 1
        
        return output


        