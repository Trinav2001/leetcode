class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';

        stack<int> stack;

        for(auto& c : s) {
            if(map.count(c)) {
                if(!stack.empty() && stack.top() == map[c]) {
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
        return stack.empty();
    }
};