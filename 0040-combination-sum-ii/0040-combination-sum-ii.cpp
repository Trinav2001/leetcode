class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, subset);

        return res;
    }

    void backtrack(vector<int>& candidates, int target, int sum, int i, vector<int>& subset) {
        if (sum == target) {
            res.push_back(subset);
            return;
        }

        if (sum > target || i >= candidates.size()) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(candidates, target, candidates[i] + sum, i + 1, subset);

        subset.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        backtrack(candidates, target, sum, i + 1, subset);
    }
};