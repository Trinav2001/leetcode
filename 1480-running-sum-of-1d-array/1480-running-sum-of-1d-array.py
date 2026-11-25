class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        prefixSum = 0
        output = []

        for num in nums:
            prefixSum += num
            output.append(prefixSum)
        
        return output
        