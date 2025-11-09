class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);

        int res = max(helper(nums1), helper(nums2));

        return res;
        
    }

    int helper (vector<int> & nums) {
        int rob1 = 0;
        int rob2 = 0;

        for (auto& num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};