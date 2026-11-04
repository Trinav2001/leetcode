class Solution:
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        n = len(cost)
        prev1 = cost[1]
        prev2 = cost[0]

        for i in range(2, n):
            cost[i] += min(prev1, prev2)
            prev2 = prev1
            prev1 = cost[i]
        
        return min(prev1, prev2)

        