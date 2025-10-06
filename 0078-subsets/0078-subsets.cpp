class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        dfs(nums, 0, subset, result);
        return result;
    }


    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& result) {
        // base condition
        if(i == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, result);

        subset.pop_back();
        dfs(nums, i + 1, subset, result);
    }

};