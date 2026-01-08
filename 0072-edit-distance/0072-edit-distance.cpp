class Solution {
public:
vector<vector<int>> memo;

    int minDistance(string word1, string word2) {

        memo.resize(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        // vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

        // for (int i = 0; i < word1.size(); i++) {
        //     dp[i][word2.size()] = word1.size() - i;
        // }

        // for (int j = 0; j < word2.size(); j++) {
        //     dp[word1.size()][j] = word2.size() - j;
        // }


        // for (int i = word1.size() - 1; i >= 0; i--) {
        //     for (int j = word2.size() - 1; j >= 0; j--) {
        //         if (word1[i] == word2[j]) {
        //             dp[i][j] = dp[i + 1][j + 1];
        //         }

        //         else {
        //             dp[i][j] = 1 + 
        //                         min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
        //         }
        //     }
        // }
        

        // return dp[0][0];

        return dfs(0, 0, word1, word2);
        
    }

    int dfs(int i, int j, string& word1, string& word2) {

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i == word1.size() && j == word2.size()) {
            return 0;
        }

        if (i == word1.size()) {
            return word2.size() - j;
        }

        if (j == word2.size()) {
            return word1.size() - i;
        }

        if (word1[i] == word2[j]) {
            memo[i][j] = dfs(i + 1, j + 1, word1, word2);
        }

        else {
            int res = min(dfs(i + 1, j, word1, word2), dfs(i, j + 1, word1, word2));
            res = min(res, dfs(i + 1, j + 1, word1, word2));
            memo[i][j] = 1 + res;
        }

        return memo[i][j];
    }
};