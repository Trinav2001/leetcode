class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Negative Marking
        for(int num : nums) {
            int idx = abs(num) - 1;
            if(nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= (-1);
        }
        return -1;
    }
};