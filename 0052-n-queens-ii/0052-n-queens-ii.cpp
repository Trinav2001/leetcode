class Solution {

unordered_set<int> col;
unordered_set<int> posDiag;
unordered_set<int> negDiag;
int res;


public:
    int totalNQueens(int n) {

        backtrack(0, n);
        return res;
    }

    void backtrack(int r, int n) {
        if(r == n) {
            res++;
            return;
        }

        for(int c = 0; c < n; c++) {
            if(col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) continue;

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            backtrack(r + 1, n);
            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }
};