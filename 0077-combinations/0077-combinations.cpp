class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        backtrack(n, k, subset, 1);
        return res;
        
    }

    void backtrack(int n, int k, vector<int>& subset, int i) {
        
        if (subset.size() == k && subset.back() <= n) {
            res.push_back(subset);
            return;
        }

        if (i > n) {
            return;
        }

        

        subset.push_back(i);
        backtrack(n, k, subset, i + 1);

        subset.pop_back();
        backtrack(n, k, subset, i + 1);
    }
};