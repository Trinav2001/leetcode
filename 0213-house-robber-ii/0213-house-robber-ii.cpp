class Solution {
public:
vector<vector<int>> memo;
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        memo.resize(nums.size(), vector<int>(2, -1));
        return max(dfs(nums, 1, 0), dfs(nums, 0, 1));

        // vector<int> nums1(nums.begin() + 1, nums.end());
        // vector<int> nums2(nums.begin(), nums.end() - 1);

        // int res = max(helper(nums1), helper(nums2));

        // return res;
        
    }

    int dfs (vector<int>& nums, int flag, int i) {
        if (i >= nums.size() || (flag && i == nums.size() - 1)) {
            return 0;
        }

        if (memo[i][flag] != -1) {
            return memo[i][flag];
        }


        memo[i][flag] = max(dfs(nums, flag, i + 1), nums[i] + 
        dfs(nums, flag, i + 2));

        return memo[i][flag];
    }

    // int helper (vector<int> & nums) {
    //     int rob1 = 0;
    //     int rob2 = 0;

    //     for (auto& num : nums) {
    //         int temp = max(num + rob1, rob2);
    //         rob1 = rob2;
    //         rob2 = temp;
    //     }

    //     return rob2;
    // }
};