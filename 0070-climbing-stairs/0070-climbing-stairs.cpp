class Solution {
private:
vector<int> memo;
public:
    int climbStairs(int n) {
        memo.resize(n + 1, -1);
        
        return dp(n);
        
    }

    int dp(int i) {
        if (i == 0 || i == 1) {
            return 1;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = dp(i - 1) + dp(i - 2);
        return memo[i];
    }
};