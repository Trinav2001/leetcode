class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;

        backtrack(0, s, partition, result);
        return result;
    }
private:
    void backtrack(int start, string s, vector<string>& partition, vector<vector<string>>& result) {
        if (start >= s.length()) {
            result.push_back(partition);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                partition.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, partition, result);
                partition.pop_back();

            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};