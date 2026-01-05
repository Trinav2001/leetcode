class Solution {
public:

// vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        // memo.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        // return dfs(text1, text2, 0, 0);

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
        
        
    }

    // int dfs (string& text1, string& text2, int i, int j) {
    //     if (i == text1.size() || j == text2.size()) {
    //         return 0;
    //     }

    //     if (memo[i][j] != -1) {
    //         return memo[i][j];
    //     }

    //     if (text1[i] == text2[j]) {
    //         memo[i][j] = 1 + dfs (text1, text2, i + 1, j + 1);
    //     }

    //     else {
    //         memo[i][j] = max(dfs(text1, text2, i, j + 1), dfs (text1, text2, i + 1, j));
    //     }

    //     return memo[i][j];
    // }
};