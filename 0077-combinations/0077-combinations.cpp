class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        dfs(n, k, 1, combo);
        return res;

    }

    void dfs(int n, int k, int i, vector<int>& combo) {
        if(i > n) {
            if(combo.size() == k) {
                res.push_back(combo);
            }
            return;
        }

        combo.push_back(i);
        dfs(n, k, i + 1, combo);

        combo.pop_back();
        dfs(n, k, i + 1, combo);

    }




};