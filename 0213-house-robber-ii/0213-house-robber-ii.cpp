class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums[0];
        }        

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        int temp1 = helper(nums1);
        int temp2 = helper(nums2);

        int ans = max(temp1, temp2);

        return ans;
        
    }

    int helper(vector<int>& nums) {

        

        int rob1 = 0;
        int rob2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};