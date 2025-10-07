class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        backtrack (candidates, subset, 0, 0, target);
        return result;
    }

    void backtrack (vector<int>& candidates, vector<int>& subset, int sum, int i, int target) {
        if (sum == target) {
            result.push_back(subset);
            return;
        }

        if (sum > target || i >= candidates.size()) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack (candidates, subset, sum + candidates[i], i + 1, target);

        subset.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        backtrack (candidates, subset, sum, i + 1, target);
    }
};