class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0;
        int r = 0;
        int n = nums.size();
        vector<int> output(n - k + 1);
        

        while(r < n) {
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if(i > dq.front()) {
                dq.pop_front();
            }

            if((r + 1) >= k) {
                output[i] = nums[dq.front()];
                i++;
            }
            r++;
        }
        return output;
    }
};