class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        int res = 0;
        for(auto& c : operations) {
            if(c == "+") {
                int top = stack.top();
                stack.pop();
                int newTop = stack.top() + top;
                stack.push(top);
                stack.push(newTop);
                res += newTop;
            }
            else if(c == "D") {
                int newTop = stack.top() * 2;
                stack.push(newTop);
                res += stack.top();
            }
            else if(c == "C") {
                res -= stack.top();
                stack.pop();
            }
            else {
                stack.push(stoi(c));
                res += stack.top();
            }
        }
        return res;
    }
};