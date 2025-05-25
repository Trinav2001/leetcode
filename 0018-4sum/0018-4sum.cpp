class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i, j, l, r;
        long long sum;
        for(i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                l = j + 1;
                r = n - 1;

                
                while(l < r) {
                    sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum > target) {
                        r--;
                    }
                    else if(sum < target) {
                        l++;
                    }
                    else {
                        output.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l - 1]) l++;
                        while(l < r && nums[r] == nums[r + 1]) r--;

                    }
                }
            }
        }
        return output;
    }
};