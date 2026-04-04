class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;
        for (auto& stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int firstLargestStone = maxHeap.top();
            maxHeap.pop();

            int secondLargestStone = maxHeap.top();
            maxHeap.pop();

            int diff = firstLargestStone - secondLargestStone;

            if (diff) {
                maxHeap.push(diff);
            }
        }

        return maxHeap.size() == 1 ? maxHeap.top() : 0; 
        
    }
};