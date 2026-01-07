class Solution {
public:
// unordered_map<string, int> memo;
    int findTargetSumWays(vector<int>& nums, int target) {
        // return dfs(nums, target, 0, 0);

        unordered_map<int, int> dp;     // sum -> number of ways(count)
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> nextDp;

            for (auto& pair : dp) {
                int total = pair.first;
                int count = pair.second;
                nextDp[total + nums[i]] += count;
                nextDp[total - nums[i]] += count;
            }

            dp = nextDp;
        }

        return dp[target];


        
    }

    // int dfs(vector<int>& nums, int target, int i, int curSum) {
    //     if (i == nums.size()) {
    //         return curSum == target;
    //     }

    //     string key = to_string(i) + "-" + to_string(curSum);

    //     if (memo.find(key) != memo.end()) {
    //         return memo[key];
    //     }

    //     memo[key] = dfs(nums, target, i + 1, curSum + nums[i]) +
    //                         dfs(nums, target, i + 1, curSum - nums[i]);

    //     return memo[key];



    // }
};