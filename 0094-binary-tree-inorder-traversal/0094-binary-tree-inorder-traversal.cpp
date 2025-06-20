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
    vector<int> inorderTraversal(TreeNode* root) {
        
        // Iterative
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* cur = root;

        while(cur || !st.empty()) {
            if(cur) {
                st.push(cur);
                cur = cur -> left;
            }
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur -> val);
                cur = cur -> right;
                
            }
        }
        return result;

        // Recursive
        // inorder(root);
        // return res;

    }
    void inorder(TreeNode* node) {
        if(node) {
            inorder(node -> left);
            res.push_back(node -> val);
            inorder(node -> right);
        }
    }
};