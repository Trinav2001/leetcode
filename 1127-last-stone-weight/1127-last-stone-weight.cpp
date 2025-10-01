class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int a = maxHeap.top();
            maxHeap.pop();

            int b = maxHeap.top();
            maxHeap.pop();

            int diff = a - b;
            if (diff) {
                maxHeap.push(diff);
            }

        }

        return maxHeap.size() == 0 ? 0 : maxHeap.top();
        
    }
}; 