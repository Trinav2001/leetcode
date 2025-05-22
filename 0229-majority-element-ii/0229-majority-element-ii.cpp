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

        for(auto& pair : map) {
            if(pair.second > x) {
                output.push_back(pair.first);
            }
        }
        return output;
    }
};