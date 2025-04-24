class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto val : nums) {
            s.insert(val);
        }
        if(s.size() == nums.size()) {
            return false;
        }
        return true;
    }
};