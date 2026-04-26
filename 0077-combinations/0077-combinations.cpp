class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        backtrack(n, k, 1, subset);
        return res;
        
    }

    void backtrack(int n, int k, int i, vector<int>& subset) {
        if (subset.size() == k) {
            res.push_back(subset);
            return;
        }

        if (i > n) {
            return;
        }

        subset.push_back(i);
        backtrack(n, k, i + 1, subset);

        subset.pop_back();
        backtrack(n, k, i + 1, subset);
    }
};