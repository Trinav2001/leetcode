class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto& val : nums) {
            map[val]++;
        }
        vector<int> output(nums.size());
        int index = 0;
        for(int val = 0; val <= 2; ) {
            if (map[val] > 0) {
                output[index++] = val;
                --map[val];
            }
            else {
                val++;
            }
        }
        
        nums.clear();
        for(auto& val : output) {
            nums.push_back(val);
        }
    }
};