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

        stack<TreeNode*> stack;

        while(!stack.empty() || cur) {
            while(cur) {
                stack.push(cur);
                cur = cur -> left;
            }

            cur = stack.top();
            stack.pop();
            n += 1;
            if(n == k) return cur -> val;

            cur = cur -> right;
        }
        return n;
    }
};