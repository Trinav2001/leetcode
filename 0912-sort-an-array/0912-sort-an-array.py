class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:

        def MergeSort(l, r):
            if l < r:
                m = l + (r - l) // 2
                MergeSort(l, m)
                MergeSort(m + 1, r)
                merge(l, m, r)
        
        def merge(l, m, r):
            nums1 = nums[l : m + 1]
            nums2 = nums[m + 1 : r + 1]

            i, j = 0, 0
            k = l

            while i < len(nums1) and j < len(nums2):
                if nums1[i] <= nums2[j]:
                    nums[k] = nums1[i]
                    i += 1
                
                else:
                    nums[k] = nums2[j]
                    j += 1
                
                k += 1
            
            while i < len(nums1):
                nums[k] = nums1[i]
                i += 1
                k += 1
            
            while j < len(nums2):
                nums[k] = nums2[j]
                j += 1
                k += 1
            
        MergeSort(0, len(nums) - 1)
        return nums

        