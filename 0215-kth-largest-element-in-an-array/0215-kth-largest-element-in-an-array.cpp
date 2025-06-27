class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // MinHeap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto& num : nums) {
            minHeap.push(num);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();

        // MaxHeap
        // priority_queue<int> maxHeap;

        // for(auto& num : nums) {
        //     maxHeap.push(num);
        // }

        // int i = 1;
        // while(i != k) {
        //     maxHeap.pop();
        //     i++;
        // }
        // return maxHeap.top();
    }
};