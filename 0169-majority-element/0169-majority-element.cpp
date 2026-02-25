class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> map;

        int n = nums.size();
        int bound = n / 2;
        

        for (auto& num : nums) {
            map[num]++;
            
            if (map[num] > bound) {
                return num;
            }
        }

        return 0;
        
    }
};