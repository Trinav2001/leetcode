class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        backtrack(candidates, target, 0, 0, subset);

        return res;
        
    }

    void backtrack(vector<int>& candidates, int target, int i, int sum, vector<int>& subset) {
        if (sum == target) {
            res.push_back(subset);
            return;
        }

        if (i >= candidates.size() || sum > target) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(candidates, target, i, sum + candidates[i], subset);

        subset.pop_back();
        backtrack(candidates, target, i + 1, sum, subset);
    }
};