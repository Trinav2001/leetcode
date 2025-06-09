class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack;

        for(int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                int index = stack.top().first;
                int val = stack.top().second;
                maxArea = max(maxArea, val * (i - index));
                start = index;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }

        while(!stack.empty()) {
            int index = stack.top().first;
            int val = stack.top().second;
            maxArea = max(maxArea, val * (static_cast<int>(heights.size()) - index));
            stack.pop();
        }
        return maxArea;
    }
};