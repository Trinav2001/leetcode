class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int result = right;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(canSplit(nums, mid, k)) {
                result = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return result;
    }

    bool canSplit(vector<int>& nums, int largest, int k) {

        int currSum = 0;
        int subArray = 1;

        for(auto& num : nums) {
            currSum += num;
            if(currSum > largest) {
                subArray += 1;
                if(subArray > k) return 0;
                currSum = num;
            }
        }
        return 1;
    }
};