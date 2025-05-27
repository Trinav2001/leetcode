class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        int min = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            if(prices[i] <= min) {
                min = prices[i];
            }
            else {
                
                profit = prices[i] - min;
            }


            if(maxProfit < profit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};