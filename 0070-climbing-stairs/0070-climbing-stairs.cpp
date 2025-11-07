class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return fun(n, memo);
        
    }

    int fun (int i, vector<int>& memo) {
        if (i == 0 || i == 1) {
            return 1;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = fun(i - 1, memo) + fun(i - 2, memo);
        return memo[i];
    }
};