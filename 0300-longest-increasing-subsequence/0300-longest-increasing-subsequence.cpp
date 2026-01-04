class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp;     // increasing (sorted) vector
        dp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {

            // extending if nums[i] is greater than last element (largest) of dp
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
                continue;
            }   

            /* Finding value in dp that is greater than or equal to nums[i]
            dp will remain sorted (ascending order) */
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[it] = nums[i];   // Improving Current Tail


        }

        return dp.size();
        
    }
};