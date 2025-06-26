class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto stone : stones) {
            maxHeap.push(stone);
        }

        while(maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if(second < first) {
                maxHeap.push(first - second);
            }
        }

        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};