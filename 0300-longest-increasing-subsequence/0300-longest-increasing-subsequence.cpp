class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Approach 1 - Time O(n^2)
        // vector<int> LIS(nums.size(), 1);
        
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] < nums[j]) {
        //             LIS[i] = max(LIS[i], 1 + LIS[j]);
        //         }
        //     }
        // }

        // return *max_element(LIS.begin(), LIS.end());  

        // Approach 2 - Time O(nlogn)
        vector<int> dp;
        dp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
                continue;
            }

            auto it = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[it] = nums[i];

        }

        return dp.size();
    }
};