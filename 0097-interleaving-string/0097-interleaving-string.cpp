class Solution {
public:
vector<vector<int>> memo;
    bool isInterleave(string s1, string s2, string s3) {
        memo.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return dfs(0, 0, s1, s2, s3);
        
    }

    bool dfs (int i, int j, string& s1, string& s2, string& s3) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i < s1.size() && s1[i] == s3[i + j] && dfs(i + 1, j, s1, s2, s3)) {
            return true;
        }

        if (j < s2.size() && s2[j] == s3[i + j] && dfs(i, j + 1, s1, s2, s3)) {
            return true;
        }   


        memo[i][j] = 0;
        return false;
    }
};