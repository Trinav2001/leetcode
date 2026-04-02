class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) {
            return false;
        }
        
        sort(nums.rbegin(), nums.rend());
        int targetSum = sum / k;
        
        vector<int> buckets(k, 0);
        return backtrack(nums, buckets, targetSum, 0);
           
    }

    bool backtrack(vector<int>& nums, vector<int>& buckets, int targetSum, int idx) {
        if (idx == nums.size()) {
            return true;
        }

        for (int i = 0; i < buckets.size(); i++) {
            if (nums[idx] + buckets[i] <= targetSum) {
                buckets[i] += nums[idx];
                if (backtrack(nums, buckets, targetSum, idx + 1)) {
                    return true;
                }
                buckets[i] -= nums[idx];
            }

            if (buckets[i] == 0) {
                break;
            }
        }
        
        return false;

    }
};