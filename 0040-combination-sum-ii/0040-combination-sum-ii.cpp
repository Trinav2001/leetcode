class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, cur);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int i, int total, vector<int>& cur) {
        if(total == target) {
            res.push_back(cur);
            return;
        }
        if(total > target || i >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, target, i + 1, total + candidates[i], cur);
        cur.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        
        dfs(candidates, target, i + 1, total, cur);
    }
};