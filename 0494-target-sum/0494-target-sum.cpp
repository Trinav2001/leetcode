class Solution {
public:
unordered_map<string, int> memo;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
        
    }

    int dfs(vector<int>& nums, int target, int i, int curSum) {
        if (i == nums.size()) {
            return curSum == target;
        }

        string key = to_string(i) + "-" + to_string(curSum);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        memo[key] = dfs(nums, target, i + 1, curSum + nums[i]) +
                            dfs(nums, target, i + 1, curSum - nums[i]);

        return memo[key];



    }
};