class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, perm, visited);

        return res;
        
    }

    void backtrack(vector<int>& nums, vector<int>& perm, vector<bool>& visited) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }


        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                perm.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, perm, visited);
                perm.pop_back();
                visited[i] = false;
            }
        }

    }
};