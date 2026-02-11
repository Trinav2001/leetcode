class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';

        stack<char> stack;

        for (auto& c : s) {
            if (map[c]) {
                if (!stack.empty() && stack.top() == map[c]) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }

            else {
                stack.push(c);
            }
        }

        if (stack.empty()) {
            return true;
        }

        return false;
    }
};