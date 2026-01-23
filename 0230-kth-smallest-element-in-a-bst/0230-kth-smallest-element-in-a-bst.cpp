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
    int kthSmallest(TreeNode* root, int k) {

        TreeNode* cur = root;
        int n = 0;

        stack<TreeNode*> st;

        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur -> left;
            }

            cur = st.top();
            st.pop();
            n++;

            if (n == k) return cur -> val;

            cur = cur -> right;
        }

        return n;
        
    }
};