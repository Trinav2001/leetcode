class Solution {
public:
vector<int> memo;
    int climbStairs(int n) {
        // memo.resize(n + 1, -1);
        // return dp(n);

        if (n <= 1) {
            return 1;
        }

        int prev1 = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    // int dp (int i) {
    //     if (i == 0 || i == 1) {
    //         return 1;
    //     }

    //     if (memo[i] != -1) {
    //         return memo[i];
    //     }

    //     memo[i] = dp(i - 1) + dp(i - 2);
    //     return memo[i];
    // }
};