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
    vector<int> preorderTraversal(TreeNode* root) {
        // Iterative

        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty()) {
            if(cur) {
                result.push_back(cur -> val);
                st.push(cur -> right);
                cur = cur -> left;
            }
            else {
                cur = st.top();
                st.pop();
            }
        }
        return result;


        // Recursive 
        // preorder(root);
        // return res;
    }

    void preorder(TreeNode* node) {
        if(node) {
            res.push_back(node -> val);
            preorder(node -> left);
            preorder(node -> right);
        }
    }
};