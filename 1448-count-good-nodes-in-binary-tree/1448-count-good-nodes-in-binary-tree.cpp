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
private:
    int res = 0;
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root -> val);

        return res;
    }

    void dfs(TreeNode* node, int maxValue) {
        if (!node) {
            return;
        }

        res += (node -> val >= maxValue) ? 1 : 0;
        maxValue = max(node -> val, maxValue);

        dfs(node -> left, maxValue);
        dfs(node -> right, maxValue);
    }
};