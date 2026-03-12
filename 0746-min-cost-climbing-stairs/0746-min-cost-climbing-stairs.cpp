class Solution {

private:
vector<int> memo;

public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        memo.resize(n + 1, -1);

        return min(dp(n - 1, cost), dp(n - 2, cost));
        
    }

    int dp(int i, vector<int>& cost) {
        
        if (i == 0 || i == 1) {
            return cost[i];
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = cost[i] + min(dp(i - 1, cost), dp(i - 2, cost));
        return memo[i];
    }
}; 