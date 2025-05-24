class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto& num : nums) {
            count[num]++;
        }
        int max = *max_element(nums.begin(), nums.end());
        int i;
        for(i = 1; i <= max; i++) {
            if(count[i] == 0) {
                return i;
            }
        }
        return i;
    }
};