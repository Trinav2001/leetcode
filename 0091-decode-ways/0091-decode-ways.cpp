class Solution {
public:
    int numDecodings(string s) {

        // Approach 1 (Bottom-Up)
        // vector<int> dp(s.size() + 1);
        // dp[s.size()] = 1;

        // for (int i = s.size() - 1; i >= 0; i--) {
        //     if (s[i] == '0') {
        //         dp[i] = 0;
        //     }
        //     else {
        //         dp[i] = dp[i + 1];

        //         if (i + 1 < s.size() && (s[i] == '1' || 
        //         (s[i] == '2' && s[i + 1] < '7'))) {
        //             dp[i] += dp[i + 2];
        //         }
        //     }
        // }

        // return dp[0];


        // Approach 2 DP (Top-Down)


        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, dp, 0);
        
    }


    int dfs (string s, unordered_map<int, int>& dp, int i) {
        if (dp.count(i)) {
            return dp[i];
        }

        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, dp, i + 1);

        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
            res += dfs(s, dp, i + 2);
        }

        dp[i] = res;
        return res;

    }
};