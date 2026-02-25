class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> map;
        map[0] = 1;
        int prefixSum = 0;
        int diff;
        
        int output = 0;

        for (auto& num: nums) {
            prefixSum += num;
            diff = prefixSum - k;

            if (map.find(diff) != map.end()) {
                output += map[diff];
            }

            map[prefixSum] += 1;

        }

        return output;
        
    }
};