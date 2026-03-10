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
    int maxDepth(TreeNode* root) {

        queue<TreeNode*> queue;
        int level = 0;

        if (!root) return 0;

        queue.push(root);
        TreeNode* cur;

        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                cur = queue.front();
                queue.pop();
                if (cur -> left) queue.push(cur -> left);
                if (cur -> right) queue.push(cur -> right);
            }

            level++;
        }

        return level;
        
    }
};