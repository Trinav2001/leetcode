class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, 0, 0, cur, target);
        return res;
    }


    void dfs(vector<int>& candidates, int i, int total, vector<int>& cur, int target) {
        if(total == target) {
            res.push_back(cur);
            return;
        }

        if(total > target || i >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, i, total + candidates[i], cur, target);

        cur.pop_back();
        dfs(candidates, i + 1, total, cur, target);
    }

};