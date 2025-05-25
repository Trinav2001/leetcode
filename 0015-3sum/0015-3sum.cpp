class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());
        int sum;
        int l, r;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0) break;
            if((i > 0) && (nums[i] == nums[i-1])) continue;

            l = i + 1;
            r = nums.size() - 1;

            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) {
                    r--;
                }
                else if(sum < 0) {
                    l++;
                }
                else {
                    output.push_back({nums[i], nums[l], nums[r]});

                    while((l < r) && (nums[l] == nums[l+1])) l++;
                    while((l < r) && (nums[r] == nums[r-1])) r--;

                    l++;
                    r--;
                }
            }
        }
        return output;
    }
};