class Solution {
public:
unordered_map<int, int> memo;
    int numDecodings(string s) {

        int res = dfs(s, 0);
        return res;
        
    }


    int dfs(string& s, int i) {
        if (i == s.size()) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }

        if (memo.find(i) != memo.end()) {
            return memo[i];
        }

        int res = dfs(s, i + 1);

        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
            res += dfs(s, i + 2);
        }

        memo[i] = res;
        return res;
    }
};