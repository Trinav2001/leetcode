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
int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        if (!root) return res;
        maxHeight(root);

        return res;
        
    }

    int maxHeight(TreeNode* node) {

        if (!node) return 0;

        int left = maxHeight(node -> left);
        int right = maxHeight(node -> right);

        res = max(res, left + right);

        return 1 + max(left, right);

    }
};