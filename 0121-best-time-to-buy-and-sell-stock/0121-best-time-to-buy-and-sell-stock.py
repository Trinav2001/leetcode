class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        output = 0

        minPrice = prices[0]

        for i in range(1, len(prices)):
            profit = 0

            if prices[i] < minPrice:
                minPrice = prices[i]

            else:
                profit = prices[i] - minPrice
            
            output = max(output, profit)
        
        return output

        