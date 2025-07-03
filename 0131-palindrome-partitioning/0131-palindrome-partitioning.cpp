class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(0, part, res, s);

        return res;
    }

private:
    void dfs(int i, vector<string>& part, vector<vector<string>>& res, string s) {
        if(i >= s.length()) {
            res.push_back(part);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            if(isPalindrome(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, part, res, s);
                part.pop_back();
            }
        }

    }

bool isPalindrome(string& s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

};