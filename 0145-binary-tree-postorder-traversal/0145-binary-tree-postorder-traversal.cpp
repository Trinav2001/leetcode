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
    vector<int> res;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Recursive
        postorder(root);
        return res;
    }

    void postorder(TreeNode* cur) {
        if(cur) {
            postorder(cur -> left);
            postorder(cur -> right);
            res.push_back(cur -> val);
        }
    }
};