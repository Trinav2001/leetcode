class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Approach 1
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (auto& coin : coins) {
                if (coin <= i) {
                    int no_of_coin_required = dp[i - coin] + 1;
                    dp[i] = min(dp[i], no_of_coin_required);
                }
            }
        }

        return dp[amount] <= amount ? dp[amount] : -1;
        
    }
};