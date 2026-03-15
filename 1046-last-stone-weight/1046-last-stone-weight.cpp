class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;

        for (auto& stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int firstHeaviestStone = maxHeap.top();
            maxHeap.pop();

            int secondHeaviestStone = maxHeap.top();
            maxHeap.pop();

            int difference = firstHeaviestStone - secondHeaviestStone;

            if (difference) {
                maxHeap.push(difference);
            }

        }

        
        return maxHeap.size() ? maxHeap.top() : 0;
        
    }
};