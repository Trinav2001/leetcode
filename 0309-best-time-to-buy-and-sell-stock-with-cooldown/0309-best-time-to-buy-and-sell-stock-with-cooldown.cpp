class Solution {
public:
unordered_map<string, int> dp;
    int maxProfit(vector<int>& prices) {

        int result = dfs(prices, 0, false);        
        return result;
    }

    int dfs (vector<int>& prices, int i, bool isBought) {
        if (i >= prices.size()) {
            return 0;
        }

        string key = to_string(i) + "-" + to_string(isBought);

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int cooldown = dfs(prices, i + 1, isBought);

        if (!isBought) {
            int buy = dfs(prices, i + 1, true) - prices[i];
            dp[key] = max(buy, cooldown);
        }

        else {
            int sell = dfs(prices, i + 2, false) + prices[i];
            dp[key] = max(sell, cooldown);
        }


        return dp[key];

    }
};