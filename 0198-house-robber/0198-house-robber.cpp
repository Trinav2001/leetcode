class Solution {

private:
vector<int> memo;
int size;

public:
    int rob(vector<int>& nums) {
        size = nums.size();
        memo.resize(size + 1, -1);

        return dfs(nums, 0);
        
    }

    int dfs(vector<int>& nums, int i) {
        if (i >= size) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
        return memo[i];
    }
};