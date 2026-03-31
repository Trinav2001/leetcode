class Solution {
vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> palindrome;
        backtrack(0, s, palindrome);
        return res;        
    }

    void backtrack(int start, string s, vector<string>& palindrome) {
        if (start == s.length()) {
            res.push_back(palindrome);
            return;
        }


        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                palindrome.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, palindrome);
                palindrome.pop_back();
            }
        }

    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};