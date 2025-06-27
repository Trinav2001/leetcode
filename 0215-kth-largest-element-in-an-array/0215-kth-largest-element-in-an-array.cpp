class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for(auto& num : nums) {
            maxHeap.push(num);
        }

        int i = 1;
        while(i != k) {
            maxHeap.pop();
            i++;
        }
        return maxHeap.top();
    }
};