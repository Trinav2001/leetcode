class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        l = 0
        r = len(numbers) - 1

        total = 0

        while l < r:
            total = numbers[l] + numbers[r]

            if total < target:
                l += 1
            
            elif total > target:
                r -= 1
            
            else:
                return [l + 1, r + 1]
        

        