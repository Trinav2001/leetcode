class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> negDiag;
    unordered_set<int> posDiag;
    int res;
public:
    int totalNQueens(int n) {
        backtrack(n, 0);
        return res;
        
    }

    void backtrack(int n, int r) {
        if (r == n) {
            res++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || negDiag.count(r - c) || posDiag.count(r + c)) {
                continue;
            }

            cols.insert(c);
            negDiag.insert(r - c);
            posDiag.insert(r + c);

            backtrack(n, r + 1);

            cols.erase(c);
            negDiag.erase(r - c);
            posDiag.erase(r + c);

        }


    }
};