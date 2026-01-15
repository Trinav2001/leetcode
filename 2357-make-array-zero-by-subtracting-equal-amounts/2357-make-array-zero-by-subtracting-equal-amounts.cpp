class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_set<int> set;

        for (int x : nums) {
            if (x > 0) set.insert(x);
        }

        return set.size();
        
    }
};