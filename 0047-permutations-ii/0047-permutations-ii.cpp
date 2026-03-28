class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> perm;
        unordered_map<int, int> count;
        for (auto& num : nums) {
            count[num]++;
        }
        backtrack(nums, perm, count);

        return res;
        
    }

    void backtrack(vector<int>& nums, vector<int>& perm, unordered_map<int, int>& count) {

        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (auto& pair : count) {
            if (pair.second > 0) {
                perm.push_back(pair.first);
                count[pair.first]--;

                backtrack(nums, perm, count);

                perm.pop_back();
                count[pair.first]++;

            }
        }

    }
};