class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for(int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());

        stack<double> stack;

        for(auto& p : pair) {
            double current = (double)(target - p.first) / p.second;
            if(stack.empty()) {                
                stack.push(current);
                continue;
            }
            double top = stack.top();
            
            stack.push(current);

            if(stack.size() >= 2 && top >= current) {
                stack.pop();
            }

        }
        return stack.size();
    }
};