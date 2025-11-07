class Solution {
public:
    int climbStairs(int n) {
        // Memoization
        // vector<int> memo(n + 1, -1);
        // return fun(n, memo);

        if (n <= 1) return 1;

        int prev2 = 1;
        int prev1 = 1;

        for (int i = 0; i < n - 1; i++) {
            int temp = prev1;
            prev1 = prev1 + prev2;
            prev2 = temp;
        }

        return prev1;
        
    }

    // Memoization
    // int fun (int i, vector<int>& memo) {
    //     if (i == 0 || i == 1) {
    //         return 1;
    //     }

    //     if (memo[i] != -1) {
    //         return memo[i];
    //     }

    //     memo[i] = fun(i - 1, memo) + fun(i - 2, memo);
    //     return memo[i];
    // }
};