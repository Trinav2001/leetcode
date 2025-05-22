class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Method - 2 DP
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = 0;           // Not holding
        dp[0][1] = -prices[0];  // Holding

        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[n-1][0];
        // int profit = 0;
        // for(int i = 1; i < prices.size(); i++) {
        //     if(prices[i] > prices[i-1]) {
        //         profit += (prices[i] - prices[i-1]);
        //     }
        // }
        // return profit;
    }
};