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
        // BFS
        vector<vector<int>> res;

        if(!root) return res;

        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            int size = queue.size();
            vector<int> level;
                        
            for(int i = size; i > 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                if(node) {
                    level.push_back(node -> val);
                    queue.push(node -> left);
                    queue.push(node -> right);
                }
            }
            if(!level.empty()) {
                res.push_back(level);
            }
        }

        return res;
        

    }
};