class Solution {
public:
unordered_map<int, int> memo;
    int coinChange(vector<int>& coins, int amount) {
        // Approach 1
        // vector<int> dp(amount + 1, amount + 1);
        // dp[0] = 0;

        // for (int i = 1; i <= amount; i++) {
        //     for (auto& coin : coins) {
        //         if (coin <= i) {
        //             int no_of_coin_required = dp[i - coin] + 1;
        //             dp[i] = min(dp[i], no_of_coin_required);
        //         }
        //     }
        // }

        // return dp[amount] <= amount ? dp[amount] : -1;

        // Approach 2
        
        int minCoins = dfs (coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
        
    }


    int dfs (vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (memo.count(amount)) {
            return memo[amount];
        }

        int result = INT_MAX;
        for (auto& coin : coins) {
            if (amount - coin >= 0) {
                int res = dfs(coins, amount - coin);
                if (res != INT_MAX) {
                    result = min(result, 1 + res);
                }
                
                
            }
            
        }

        memo[amount] = result;
        return result;

    }
};