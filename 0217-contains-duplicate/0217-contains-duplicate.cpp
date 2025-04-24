class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        // Method 3
        s.reserve(nums.size());   // avoiding rehashing
        for(auto val : nums) {
            if(!s.insert(val).second) {
                return true;
            }
        }
        return false;


        // Method 2
        // unordered_map<int, int> m;
        // m.reserve(nums.size());
        // for(auto val : nums) {
        //     m[val]++;
        //     if(m[val] > 1) {
        //         return true;
        //     }
        // }
        // return false;


        // Method 1
        // for(auto val : nums) {
        //     s.insert(val);
        // }
        // if(s.size() == nums.size()) {
        //     return false;
        // }
        // return true;
    }
};