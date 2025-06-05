class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for(int i = 0; i < asteroids.size(); i++) {
            int current = asteroids[i];
            if(current > 0) stack.push(current);

            else {
                if (stack.empty() || stack.top() < 0)  stack.push(current);
                else {
                    while(!stack.empty() && stack.top() > 0 && abs(stack.top()) < abs(current)) {
                        stack.pop();
                    }
                    if(stack.empty()) stack.push(current);
                    else if(stack.top() < 0) stack.push(current);
                    else if(abs(stack.top()) == abs(current)) stack.pop();
                    
                }
            }
        }


        vector<int> res;
        while(!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};