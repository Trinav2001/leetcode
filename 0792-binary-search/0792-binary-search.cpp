class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;   // to tackle overflow in mid = (left+right)/2. 2^31 + 2^31 would overflow.
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};