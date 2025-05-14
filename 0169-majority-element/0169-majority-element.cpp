class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto key : nums) {
            map[key] += 1;
        }
        int ans = nums[0];
        int freq = -1;
        for(auto val : map) {
            if(val.second > freq) {
                freq = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
};