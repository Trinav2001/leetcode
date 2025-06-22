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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        DFS(root, res);
        return res;
    }

private:
    int DFS(TreeNode* root, int& res) {
        if(root == NULL) return 0;

        int left = DFS(root -> left, res);
        int right = DFS(root -> right, res);

        res =  max(res, left + right);

        return 1 + max(left, right);
    }
};