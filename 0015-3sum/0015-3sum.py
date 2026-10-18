class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:

        total = 0
        output = []
        nums.sort()

        for k in range(len(nums) - 2):
            if nums[k] > 0:
                return output
            
            if k > 0 and nums[k] == nums[k - 1]:
                continue

            l = k + 1
            r = len(nums) - 1

            while l < r:
                total = nums[k] + nums[l] + nums[r]
                if total < 0:
                    l += 1
                
                elif total > 0:
                    r -= 1
                
                else:
                    output.append([nums[k], nums[l], nums[r]])

                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1

                    l += 1
                    r -= 1

        return output 
            

        