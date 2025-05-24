class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        int currentSum = 0;
        int diff;
        int output = 0;
        prefixSum[0] = 1;
        for(auto& num : nums) {
            currentSum += num;
            diff = currentSum - k;
            output += prefixSum[diff];
            prefixSum[currentSum]++;
        }

        return output;
    }
};