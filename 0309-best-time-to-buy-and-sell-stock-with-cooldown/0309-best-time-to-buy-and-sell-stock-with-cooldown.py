class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        dp = {}

        def dfs(i, Bought):
            if i >= len(prices):
                return 0

            if (i, Bought) in dp:
                return dp[(i, Bought)]

            cooldown = dfs(i + 1, Bought)

            if not Bought:
                buy = dfs(i + 1, not Bought) - prices[i]
                dp[(i, Bought)] = max(buy, cooldown)
            
            else:
                sell = dfs(i + 2, not Bought) + prices[i]
                dp[(i, Bought)] = max(sell, cooldown)
            
            return dp[(i, Bought)]
                
        return dfs(0, False)
        