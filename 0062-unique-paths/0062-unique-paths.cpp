class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> row(n, 1);
        for (int i = 0; i < m - 1; i++) {
            vector<int> newRow(n, 1);

            for (int j = n - 2; j >= 0; j--) {
                newRow[j] = newRow[j + 1] + row[j];
            }

            row = newRow;
        }

        return row[0];
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[1][1] = 1;
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (i == 1 && j == 1) continue;

        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }

        // return dp[m][n];
    }
};