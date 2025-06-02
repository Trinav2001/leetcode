class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;

        
        for(auto&c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else if (!stack.empty()) {
                if(c == ')' && stack.top() == '(') {
                    stack.pop();
                }
                else if(c == '}' && stack.top() == '{') {
                    stack.pop();
                }
                else if(c == ']' && stack.top() == '[') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
            
        }

        if(!stack.empty()) return false;

        return true;
    }
};