class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        seen = set()
        output = []

        for num in nums1:
            seen.add(num)
        
        for num in nums2:
            if num in seen:
                output.append(num)
                seen.remove(num)
        
        return output
        