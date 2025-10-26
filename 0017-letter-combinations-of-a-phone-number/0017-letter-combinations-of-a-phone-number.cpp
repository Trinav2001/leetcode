class Solution {
public:
vector<string> digitIndex = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> result;
    vector<string> letterCombinations(string digits) {
        backtrack(0, "", digits, result);
        return result;
        
    }

    void backtrack(int i, string s, string digits, vector<string>& result) {
        if (s.length() == digits.length()) {
            result.push_back(s);
            return;
        }

        for (auto& c : digitIndex[digits[i] - '0']) {
            backtrack(i + 1, s + c, digits, result);
        }

        
    }
};