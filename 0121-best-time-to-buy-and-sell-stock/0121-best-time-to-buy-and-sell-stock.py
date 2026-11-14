class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minPrice = float("infinity")
        maxProfit = 0

        for price in prices:
            if price < minPrice:
                minPrice = price
            
            else:
                maxProfit = max(maxProfit, price - minPrice)
        
        return maxProfit
        