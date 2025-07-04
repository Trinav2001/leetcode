class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return res;
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i, string cur, string& digits) {
        if(cur.length() == digits.length()) {
            res.push_back(cur);
            return;
        }

        for(auto& c : digitToChar[digits[i] - '0']) {
            backtrack(i + 1, cur + c, digits);
        }

    }
};