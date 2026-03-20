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
    int count = 0;
    int flag = 0;
    TreeNode* res=NULL;

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res -> val;
    }

    TreeNode* inorder(TreeNode* root, int k) {
        if (flag == 1) return res;
        if (!root || count == k) return res;

        inorder(root -> left, k);
        
        count++;
        if (count == k) {
            res = root;
            flag = 1;
            return res;
        }
        inorder(root -> right, k);

        return res;
        
    }
};