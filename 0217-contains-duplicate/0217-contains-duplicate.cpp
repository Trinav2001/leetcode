class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> set;
        set.reserve(nums.size());

        for (auto& num : nums) {
            auto pair = set.insert(num);
            if (!pair.second) {
                return true;
            }
        }

        return false;
        
    }
};