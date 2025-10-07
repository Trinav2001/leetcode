class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> subset;
        backtrack (subset, 0, 0, target, candidates);
        return result;
    }

    void backtrack (vector<int>& subset, int sum, int i, int target, vector<int>& candidates)
    {
        if (sum == target) {
            result.push_back(subset);
            return;
        }

        if (sum > target || i >= candidates.size()) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack (subset, sum + candidates[i], i, target, candidates);

        subset.pop_back();
        backtrack (subset, sum, i + 1, target, candidates);
    }
};