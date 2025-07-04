class Solution {
public:
int target;
vector<bool> used;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        used.assign(nums.size(), false);
        target = sum / k;
        return backtrack(nums, k, 0, 0);
    }

    bool backtrack(vector<int>& nums, int k, int subsetSum, int start) {
        if(k == 0) return true;

        if(subsetSum == target) return backtrack(nums, k - 1, 0, 0);

        for(int i = start; i < nums.size(); i++) {
            if(!used[i] && subsetSum + nums[i] <= target) {
                used[i] = true;
                if (backtrack(nums, k, subsetSum + nums[i], i + 1)) return true;
                used[i] = false;
            }
        }
        return false;
    }

};