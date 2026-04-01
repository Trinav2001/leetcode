class Solution {
private:
    vector<string> alphabets = {"", "", "abc", "def", "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"};
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        backtrack(digits, "", 0);

        return res;
        
    }

    void backtrack(string digits, string str, int i) {
        if (str.size() == digits.size()) {
            res.push_back(str);
            return;
        }

        for (auto& c : alphabets[digits[i] - '0']) {
            backtrack(digits, str + c, i + 1);
        }
    }
};