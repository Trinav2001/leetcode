class Solution {

private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {

        backtrack(0, 0, "", n);
        return res;
        
    }

    void backtrack(int open, int close, string str, int n) {
        if (open == n && close == n) {
            res.push_back(str);
            return;
        }

        if (open < n) {
            str += "(";
            backtrack(open + 1, close, str, n);
            str.pop_back();
        }

        if (close < open) {
            str += ")";
            backtrack(open, close + 1, str, n);
            str.pop_back();
        }
    }


};