class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;
        int res = 100000;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[start] > nums[mid]) {
                res = min(res, nums[mid]);
                end = mid - 1;

            }

            else {
                res = min(res, nums[start]);
                start = mid + 1;
            }
        }
        return res;
        
    }
};