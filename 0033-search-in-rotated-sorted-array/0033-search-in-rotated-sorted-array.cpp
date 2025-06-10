class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[left]) {
                if(target >= nums[left] && target <= nums[mid]) right = mid;
                else left = mid + 1;
            }

            else {
                if(target != nums[left]) left++;
                else {
                    res = left;
                    break;
                }
            }

        }
        return res;
    }
};