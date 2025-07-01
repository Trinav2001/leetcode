class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        // dfs(n, k, 1, combo);
        backtrack(1, combo, k, n);
        return res;

    }

    // Backtracking
    void backtrack(int start, vector<int>&  combo, int k, int n) {
        if(combo.size() == k) {
            res.push_back(combo);
            return;
        }

        for(int i = start; i < n + 1; i++) {
            combo.push_back(i);
            backtrack(i + 1, combo, k, n);
            combo.pop_back();
        }
    }

    // void dfs(int n, int k, int i, vector<int>& combo) {
    //     if(i > n) {
    //         if(combo.size() == k) {
    //             res.push_back(combo);
    //         }
    //         return;
    //     }

    //     combo.push_back(i);
    //     dfs(n, k, i + 1, combo);

    //     combo.pop_back();
    //     dfs(n, k, i + 1, combo);

    // }




};