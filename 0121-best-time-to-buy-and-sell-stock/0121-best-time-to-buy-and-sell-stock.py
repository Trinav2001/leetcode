class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0
        minPrice = float("infinity")

        for i in range(len(prices)):

            if prices[i] < minPrice:
                minPrice = prices[i]
            
            else:
                profit = max(profit, prices[i] - minPrice)
        
        return profit

        