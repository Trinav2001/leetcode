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
        // Iterative
        TreeNode* cur;
        vector<int> result;
        stack<TreeNode*> st;
        vector<bool> visit;
        visit.push_back(false);
        st.push(root);

        while(!st.empty()) {
            bool v = visit.back();
            cur = st.top();
            st.pop();
            visit.pop_back();

            if(cur) {
                if(v) result.push_back(cur -> val);
                else {
                    st.push(cur);
                    visit.push_back(true);
                    st.push(cur -> right);
                    visit.push_back(false);
                    st.push(cur -> left);
                    visit.push_back(false);
                }
            }
            
        }
        return result;
        
        // Recursive
        // postorder(root);
        // return res;
    }

    void postorder(TreeNode* cur) {
        if(cur) {
            postorder(cur -> left);
            postorder(cur -> right);
            res.push_back(cur -> val);
        }
    }
};