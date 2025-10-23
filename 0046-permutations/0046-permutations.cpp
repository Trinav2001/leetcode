class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        backtrack(path, visited, nums);
        return result;

    }

    void backtrack(vector<int>& path, vector<bool>& visited, vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(nums[i]);
                backtrack(path, visited, nums);
                path.pop_back();
                visited[i] = false;
            }
        }

    }
};