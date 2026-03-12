class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int prev1 = cost[1];
        int prev2 = cost[0];

        for (int i = 2; i < n; i++) {
            cost[i] += min(prev1, prev2);
            prev2 = prev1;
            prev1 = cost[i];
        }

        return min(cost[n - 1], cost[n - 2]);
        
    }
};