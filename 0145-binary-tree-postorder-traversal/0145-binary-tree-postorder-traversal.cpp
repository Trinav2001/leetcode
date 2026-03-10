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
    vector<int> postorderTraversal(TreeNode* root) {
        // Method - 2
        vector<bool> visited;
        vector<int> res;
        TreeNode* cur;
        stack<TreeNode*> st;

        st.push(root);
        visited.push_back(false);
        
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            bool v = visited.back();
            visited.pop_back();

            if (cur) {
                if (v) {
                    res.push_back(cur -> val);
                }

                else {
                    
                    st.push(cur);
                    visited.push_back(true);

                    st.push(cur -> right);
                    visited.push_back(false);

                    st.push(cur -> left);
                    visited.push_back(false);
                }
            }
            
        }

        return res;
        
        
        // Method - 1
        // stack<TreeNode*> st1;
        // stack<TreeNode*> st2;
        // vector<int> res;

        // if (!root) {
        //     return res;
        // }

        // st1.push(root);
        // TreeNode* cur;

        // while (!st1.empty()) {
        //     cur = st1.top();
        //     st1.pop();
            
        //     st2.push(cur);

        //     if (cur -> left) st1.push(cur -> left);
        //     if (cur -> right) st1.push(cur -> right);
            
        // }

        // while (!st2.empty()) {
        //     res.push_back(st2.top() -> val) ;
        //     st2.pop();
        // }

        // return res;
        
    }
};