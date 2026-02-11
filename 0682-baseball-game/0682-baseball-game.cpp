class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> stack;

        for (auto& op : operations) {
            if (op == "C") {
                stack.pop();
            }

            else if (op == "D") {
                int a = stack.top();
                stack.push(a * 2);                
            }

            else if (op == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();

                stack.push(b);
                stack.push(a);
                stack.push(a + b);
            }

            else {
                stack.push(stoi(op));
            }
        }

        int sum = 0;

        while (!stack.empty()) {
            cout<<stack.top()<< " ";
            sum = sum + stack.top();
            stack.pop();
        }

        return sum;

        
        
    }
};