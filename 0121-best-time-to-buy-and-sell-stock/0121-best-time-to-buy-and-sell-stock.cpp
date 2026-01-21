class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min = prices[0];

        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = 0;
            if (prices[i] <= min) {
                min = prices[i];
            }

            else {
                profit = prices[i] - min;
            }


            maxProfit = max(maxProfit, profit);
            
        }

        return maxProfit;
        
    }
};