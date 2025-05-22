class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> output;
        int n = nums.size();
        int x = n / 3;
        for(auto& num : nums) {
            map[num]++;
        }

        for(auto& val : nums) {
            if(map[val] > x && find(output.begin(), output.end(), val) == output.end()) {
                output.push_back(val);
            }
        }
        return output;
    }
};