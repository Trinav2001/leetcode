/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root -> val);
    }

private:
    int dfs(TreeNode* root, int maxValue) {
        if(!root) return 0;

        int res = (root -> val >= maxValue) ? 1 : 0;
        maxValue = max(root -> val, maxValue);
        res += dfs(root -> left, maxValue);
        res += dfs(root -> right, maxValue);
        return res;

    }
};