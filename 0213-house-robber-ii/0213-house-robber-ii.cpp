class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        int first = dp(nums1);
        int second = dp(nums2);

        return max(first, second);
        
    }

    int dp(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }
        
        
        int rob2 = nums[0];
        int rob1 = max(nums[1], rob2);

        for (int i = 2; i < n; i++) {
            int temp = max(nums[i] + rob2, rob1);
            rob2 = rob1;
            rob1 = temp;
        }

        return max(rob1, rob2);

        
        
    }
};