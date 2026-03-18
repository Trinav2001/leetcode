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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> output;

        if(!root) {
            return output;
        }

        TreeNode* cur;

        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            int levelSize = queue.size();

            vector<int> level;
            for (int i = 0; i < levelSize; i++) {
                cur = queue.front();
                queue.pop();
                level.push_back(cur -> val);

                if (cur -> left) {
                    queue.push(cur -> left);
                }
                if (cur -> right) {
                    queue.push(cur -> right);
                }
            }

            output.push_back(level);
        }

        return output;
    }
};